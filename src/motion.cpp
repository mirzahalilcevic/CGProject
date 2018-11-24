#include "motion.h"
#include "data.h"

void calculate_animation(int x, int y)
{
    // postavlja smjer animacije
    if (x >= (window_width / 2))
        direction = 1;
    else
        direction = 0;

    // postavlja brzinu animacije
    speed = abs(x - window_width / 2) / 1000.0f;

    // ako je ukljucena, postavlja faktor skaliranja za animaciju sa skaliranjem
    if (scale_animation) {
        scale_factor = abs(y - window_height) / 300.0f;
        glutPostRedisplay();
    }
}

void motion(int x, int y)
{
    calculate_animation(x, y);
}

void passive_motion(int x, int y)
{
    calculate_animation(x, y);
}
