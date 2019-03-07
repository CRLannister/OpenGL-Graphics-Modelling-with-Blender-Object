#include "header_files/Math.h"
#include <iostream>
#include "GL/glut.h"
#include "header_files/load.h"
#include "header_files/Graphics.h"
#include "header_files/Transformation.h"
#include "header_files/main.h"
using namespace std;

// global variables
Vec3 CAMERA(0, 0, 40), TARGET(0, 0, 0), LIGHT(10, 10, 10);
Scene SCENE;
float FIELD_OF_VIEW = 45, ANGLE_X = 0, ANGLE_Y = 0, ANGLE_Z = 0;
Window WINDOW;
int type = 1;
int axis_type = 2;
float scale = 1.0;

void display();
void keyboard(unsigned char key, int x, int y);
void special(int key, int x, int y);

int main(int argc, char **argv)
{
    SCENE.load(string(argv[1]));
    WINDOW = Window(1366, 768, -1, -200);

    // initialize GL
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW.width, WINDOW.height);
    glutCreateWindow("ICTC");

    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW.width, 0, WINDOW.height);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);

    WINDOW.start();
}

void display()
{
    WINDOW.clear();
    if(type == 1)
    WINDOW.render(SCENE, CAMERA, TARGET, LIGHT, FIELD_OF_VIEW, scale, axis_type, ANGLE_X, ANGLE_Y, ANGLE_Z);
    else if(type == 2)
    WINDOW.wireframe(SCENE, CAMERA, TARGET, FIELD_OF_VIEW, scale, axis_type,  ANGLE_X, ANGLE_Y, ANGLE_Z);
    WINDOW.refresh();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'x')
        type = 1;
    if (key == 'z')
        type = 2;

    if (key == 27)
        exit(EXIT_SUCCESS);

    else if (key == 'w')
        CAMERA.z--;
    else if (key == 's')
        CAMERA.z++;
    else if (key == 'a')
        CAMERA.x--;
    else if (key == 'd')
        CAMERA.x++;
    else if (key == 'q')
        CAMERA.y--;
    else if (key == 'e')
        CAMERA.y++;

    else if (key == 'i')
        LIGHT.z--;
    else if (key == 'k')
        LIGHT.z++;
    else if (key == 'j')
        LIGHT.x--;
    else if (key == 'l')
        LIGHT.x++;
    else if (key == 'u')
        LIGHT.y--;
    else if (key == 'o')
        LIGHT.y++;

    else if (key == 't')
        TARGET.z--;
    else if (key == 'g')
        TARGET.z++;
    else if (key == 'f')
        TARGET.x--;
    else if (key == 'h')
        TARGET.x++;
    else if (key == 'r')
        TARGET.y--;
    else if (key == 'y')
        TARGET.y++;
    else if (key == 'b')
        axis_type = 1;
    else if (key == 'n')
        axis_type = 2;
    else if (key == 'm')
        axis_type = 3;


    glutPostRedisplay();
}

void special(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT)
        ANGLE_Y -= 1;
    else if (key == GLUT_KEY_RIGHT)
        ANGLE_Y += 1;
    else if (key == GLUT_KEY_DOWN)
        ANGLE_Z -= .01;
    else if (key == GLUT_KEY_UP)
        ANGLE_Z += .01;
    else if (key == GLUT_KEY_PAGE_UP)
        ANGLE_X += 1;
    else if (key == GLUT_KEY_PAGE_DOWN)
        ANGLE_X -= 1;
    else if (key ==GLUT_KEY_F1)
        scale = scale* 1.1;
    else if (key ==GLUT_KEY_F2)
        scale = scale* 0.9;



    glutPostRedisplay();
}
