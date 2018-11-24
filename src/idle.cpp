#include "idle.h"
#include "data.h"

void idle()
{
    // ako je ukljucena, odrzava animaciju sa rotacijom
    if (rotate_animation) {
        if ((angle += (0.001f + speed)) >= 360.0f) angle = 0.0f;
        glutPostRedisplay();
    }
    // ako je ukljucena, odrzava animaciju sa translacijom
    if (translate_animation) {
        position += (0.0001f + (direction ? speed : -speed) / 20.0f);
        if (position > 10.0f)
            position = -15.0f;
        else if (position < -15.0f)
            position = 10.0f;
        glutPostRedisplay();
    }
}
