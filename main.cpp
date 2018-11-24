#include <windows.h>
#include <GL/glut.h>

#include "data.h"
#include "init.h"
#include "display.h"
#include "keyboard.h"
#include "mouse.h"
#include "motion.h"
#include "idle.h"
#include "reshape.h"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(window_width, window_height);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2,
                           (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2);
    glutCreateWindow("Završni projekat");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutPassiveMotionFunc(passive_motion);

    init();
    glutMainLoop();

    return 0;
}
