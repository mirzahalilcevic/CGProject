#include "keyboard.h"
#include "data.h"

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case '0':
        // ukljucuje/iskljucuje prvi izvor svjetlosti
        light0 = (light0 + 1) % 2;
        switch (light0) {
        case 0:
            glDisable(GL_LIGHT0);
            break;
        case 1:
            glEnable(GL_LIGHT0);
            break;
        }
        break;
    case '1':
        // ukljucuje/iskljucuje drugi izvor svjetlosti
        light1 = (light1 + 1) % 2;
        switch (light1) {
        case 0:
            glDisable(GL_LIGHT1);
            break;
        case 1:
            glEnable(GL_LIGHT1);
            break;
        }
        break;
    case '2':
        // ukljucuje/iskljucuje prvi materijal
        mat0_enabled = !mat0_enabled;
        break;
    case '3':
        // ukljucuje/iskljucuje drugi materijal
        mat1_enabled = !mat1_enabled;
        break;
    case 32:
        // space - mijenja odabir kamere
        camera = (camera + 1) % 2;
        break;
    case 27:
        // esc - program se terminira
        exit(0);
        break;
    }
    glutPostRedisplay();
}
