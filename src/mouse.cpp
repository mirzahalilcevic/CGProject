#include "mouse.h"
#include "data.h"

void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_UP)
        return;

    switch (button) {
    case GLUT_LEFT_BUTTON:
        // ukljucuje/iskljucuje animaciju sa rotacijom
        rotate_animation = !rotate_animation;
        break;
    case GLUT_MIDDLE_BUTTON:
        // ukljucuje/iskljucuje animaciju sa translacijom
        translate_animation = !translate_animation;
        break;
    case GLUT_RIGHT_BUTTON:
        // ukljucuje/iskljucuje animaciju sa skaliranjem
        scale_animation = !scale_animation;
        break;
    }
}
