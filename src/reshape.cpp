#include "reshape.h"
#include "data.h"

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    window_width = width;
    window_height = height;
}
