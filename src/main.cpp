#include<cmath>
#include<iostream>


// GLEW
#define GLEW_STATIC
//#include <GL/glew.h>

#include <glad/glad.h>

//GLFW
#include<GLFW/glfw3.h>

//glm for matrix and vectors
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other includes
#include "my_shader.h"
//#include "New_shader.h"
#include "objreader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


void processInput(GLFWwindow *window);
void framebuffer_size_callback(GLFWwindow * window , int dummy_width, int dummy_height);
void mouse_callback(GLFWwindow* window, double xpos , double ypos);

//settings
const int SCREEN_WIDTH=1000;
const int SCREEN_HEIGHT=700;
int change_width, change_height;

//camera
glm::vec3 cameraPos = glm::vec3(0.0f,0.0f,3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f,0.0f,-1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f,1.0f,0.0f);

//mouse and 3d
bool firstMouse = true;
float yaw = -90.0f;
float pitch = 0.0f;
double lastX =   SCREEN_WIDTH / 2.0f ;
double lastY = SCREEN_HEIGHT /2.0f ;
float fov = 45.0f; 

//timing
double deltaTime=0.0f;
double lastFrame=0.0f;

int main() {
    //initialize and configure
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    //window
    GLFWwindow* window=glfwCreateWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"ICTC",nullptr, nullptr);
    if (window== nullptr){
        std::cout<<"failed to create window"<<std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // Define the viewport dimensions
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
//    glfwSetCursorPosCallback(window,mouse_callback);
    //tell glfw to capture our mouse
//    glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }

    //configure opengl state
    glEnable(GL_DEPTH_TEST);



    //build and compile our shader program
    Shader ourShader("src/shader.vs","src/shader.fs");

    //load file
    File f("resource/new_ictc_triangulated.obj");


    unsigned int VAO ,VBO ,EBO  ;
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glGenBuffers(1,&EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(float)*(f.vertices.size()),static_cast<void*>(f.vertices.data()),GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int)*(f.indices.size()),static_cast<void*>(f.indices.data()),GL_STATIC_DRAW);

    //position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //set wireframe mode
//    glPolygonMode( GL_FRONT_AND_BACK,GL_LINE);
    glPolygonMode( GL_FRONT_AND_BACK,GL_TRIANGLES);

    //ourShader.use();


    while(!glfwWindowShouldClose(window))
    {
        //per-frame time logic
        double currentFrame=glfwGetTime();
        deltaTime=currentFrame-lastFrame;
        lastFrame=currentFrame;


        //input
        processInput(window);

        //render
        glClearColor(0.5,0.5,0.5,1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwGetFramebufferSize( window, &change_width, &change_height );

        // Activate shader
        ourShader.use();
        //create transformations

        //model matrix
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 translate = glm::translate(glm::mat4(1.f), glm::vec3(0.f, -0.7f, 0.f));
        model = translate * model;

        model=glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        GLint modelLoc = glGetUniformLocation(ourShader.ID, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE,glm::value_ptr(model));

        //view matrix
        glm::mat4 view = glm::mat4(1.0f);
        view = glm::lookAt(cameraPos,cameraFront+cameraPos,cameraUp);
        GLint viewLoc = glGetUniformLocation(ourShader.ID,"view");
        glUniformMatrix4fv(viewLoc,1,GL_FALSE,glm::value_ptr(view));

        //projection matrix
        glm::mat4 projection ;
        projection = glm::perspective(glm::radians(fov), float(SCREEN_WIDTH)/SCREEN_HEIGHT, 0.1f, 100.0f);
        GLint projectionLoc = glGetUniformLocation(ourShader.ID,"projection");
        glUniformMatrix4fv(projectionLoc,1,GL_FALSE,glm::value_ptr(projection));

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, f.indices.size(), GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteBuffers(1,&EBO);
    glfwTerminate();
    return 0;

}

void framebuffer_size_callback(GLFWwindow * window, int dummy_width, int dummy_height)
{
    dummy_height = change_height;
    dummy_width = change_width;
    glViewport(0,0,dummy_width ,dummy_height);
    
}



void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window , GLFW_KEY_ESCAPE)==GLFW_PRESS)
       glfwSetWindowShouldClose(window ,true);

    double cameraSpeed=2.5*deltaTime;
    if(glfwGetKey(window,GLFW_KEY_W)==GLFW_PRESS)
        cameraPos +=float(cameraSpeed)*cameraFront;
    if(glfwGetKey(window,GLFW_KEY_S)==GLFW_PRESS)
        cameraPos -= float(cameraSpeed)*cameraFront;
    if(glfwGetKey(window,GLFW_KEY_D)==GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront,cameraUp))*float(cameraSpeed);
    if(glfwGetKey(window,GLFW_KEY_A)==GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront,cameraUp))*float(cameraSpeed);

}

//whenever the mouse moves ,this callback is called
void mouse_callback(GLFWwindow* window,double xpos , double ypos)
{
   if (firstMouse)
   {
       lastX=xpos;
       lastY=ypos;
       firstMouse=false;
   }
   double xoffset = xpos -lastX;
   double yoffset = lastY - ypos;
   lastY=ypos;
   lastX=xpos;

   float sensitivity=0.1f;
   xoffset *= sensitivity;
   yoffset *= sensitivity;

   yaw += xoffset;
   pitch += yoffset;

   //limit pitch within bounds
   if (pitch >89.0f)
        pitch = 89.0f;
   if (pitch <-89.0f)
        pitch = -89.0f;     
    
    glm::vec3 front;
    front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
    front.y = sin(glm::radians(pitch));
    front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
    cameraFront = glm::normalize(front);
}
