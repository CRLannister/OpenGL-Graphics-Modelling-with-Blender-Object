#ifndef SHADER_H
#define SHADER_H
//#include <GL/glew.h>

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader
{
public:
    GLuint ID;
    std::string vertexCode;
    std::string fragmentCode;

    std::stringstream vShaderStream, fShaderStream;

    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
    {
        // 1. retrieve the vertex/fragment source code from filePath
        std::ifstream vShaderFile("src/shader.vs", std::ios::in);
        std::ifstream fShaderFile(fragmentPath);
        // ensure ifstream objects can throw exceptions:
//        vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
//        fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        vShaderFile.exceptions (std::ifstream::badbit);
        fShaderFile.exceptions (std::ifstream::badbit);
        try
        {
//            vShaderFile.open(vertexPath, std::ios_base::in);
//            fShaderFile.open(fragmentPath);
//            if(vShaderFile.is_open()){
//                std::cout<<"nice\n";
//            }
//            std::cout<<vShaderFile<<std::endl;
            // read file's buffer contents into streams
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            // close file handlers
            vShaderFile.close();
            fShaderFile.close();
            // convert stream into string
            vertexCode   = vShaderStream.str();
            fragmentCode = fShaderStream.str();
//            std::cout<<vertexCode<<std::endl;

        }
        catch (std::ifstream::failure e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
        const GLchar* vShaderCode = vertexCode.c_str();
        const GLchar * fShaderCode = fragmentCode.c_str();
        // 2. compile shaders
        GLuint vertex, fragment;

        // vertex shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
//        std::cout<<vShaderCode<<std::endl;

        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        GLint success;
        GLchar infoLog[1024];

        // Print compile errors if any
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertex, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED --- vertex\n" << infoLog << std::endl;
        }


//      checkCompileErrors(vertex, "VERTEX");


        // fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
//        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
//        if (!success)
//        {
//            glGetShaderInfoLog(fragment, 512, NULL, infoLog);
//            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//        }

        checkCompileErrors(fragment, "FRAGMENT");


        // shader Program
        this->ID = glCreateProgram();
        glAttachShader(this->ID, vertex);
        glAttachShader(this->ID, fragment);
        glLinkProgram(this->ID);
        // Print linking errors if any
//        glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
//        if (!success)
//        {
//            glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
//            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//        }

        checkCompileErrors(this->ID, "PROGRAM");


        // delete the shaders as they're linked into our program now and no longer necessary
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }
    // activate the shader
    // ------------------------------------------------------------------------
    void use() 
    { 
        glUseProgram(this->ID);
    }
    // utility uniform functions
    // ------------------------------------------------------------------------
    void setBool(const std::string &name, bool value) const
    {         
        glUniform1i(glGetUniformLocation(this->ID, name.c_str()), (int)value);
    }
    // ------------------------------------------------------------------------
    void setInt(const std::string &name, int value) const
    { 
        glUniform1i(glGetUniformLocation(this->ID, name.c_str()), value);
    }
    // ------------------------------------------------------------------------
    void setFloat(const std::string &name, float value) const
    { 
        glUniform1f(glGetUniformLocation(this->ID, name.c_str()), value);
    }

private:
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    void checkCompileErrors(GLuint shader, std::string type)
    {
        GLint success;
        GLchar infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
};
#endif