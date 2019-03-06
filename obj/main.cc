#include "header_files/Math.h"
#include <iostream>
#include "GL/glut.h"
#include "header_files/Scene.h"
#include "header_files/Graphics.h"
#include "header_files/Transformation.h"
#include "header_files/main.h"
using namespace std;

// global variables
Vec3 CAMERA(0, 0, 20), TARGET(0, 0, 0), LIGHT(10, 10, 10);
Scene SCENE;
float FIELD_OF_VIEW = 45, ANGLE = 0;
Window WINDOW;

void display();
void keyboard(unsigned char key, int x, int y);
void special(int key, int x, int y);

int main(int argc, char **argv)
{
    SCENE.load(string(argv[1]));
    WINDOW = Window(800, 600, -1, -200);

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
#ifdef SOLID
    WINDOW.render(SCENE, CAMERA, TARGET, LIGHT, FIELD_OF_VIEW, ANGLE);
#else
    WINDOW.wireframe(SCENE, CAMERA, TARGET, FIELD_OF_VIEW, ANGLE);
#endif
    WINDOW.refresh();
}

void keyboard(unsigned char key, int x, int y)
{
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

    glutPostRedisplay();
}

void special(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT)
        ANGLE -= 5;
    else if (key == GLUT_KEY_RIGHT)
        ANGLE += 5;

    glutPostRedisplay();
}
