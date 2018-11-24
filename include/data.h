#ifndef DATA_H
#define DATA_H

#include <GL/glut.h>
#include <stdint.h>

extern
const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[600 * 300 * 4 + 1];
} gimp_image;

extern uint16_t window_width;
extern uint16_t window_height;
extern uint8_t camera;
extern uint8_t direction;
extern float speed;
extern GLfloat angle;
extern GLfloat position;
extern GLfloat scale_factor;
extern bool rotate_animation;
extern bool translate_animation;
extern bool scale_animation;
extern uint8_t light0;
extern uint8_t light1;
extern GLfloat mat0[];
extern GLfloat mat1[];
extern GLfloat mat_off[];
extern bool mat0_enabled;
extern bool mat1_enabled;
extern GLUquadric* tire_quad;
extern GLUquadric* rim_quad;

#endif // DATA_H
