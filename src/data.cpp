#include <data.h>

// sirina i visina prozora
uint16_t window_width = 800;
uint16_t window_height = 600;

// odabir kamere
uint8_t camera = 0;

// smjer animacije
uint8_t direction = 1;

// brzina animacije
float speed = 0.0f;

// parametri za animaciju
GLfloat angle = 0.0f;
GLfloat position = 0.0f;
GLfloat scale_factor = 1.0f;

// varijable za pracenje stanja animacije
bool rotate_animation = false;
bool translate_animation = false;
bool scale_animation = false;

// pomocne varijable za osvjetljenje
uint8_t light0 = 1;
uint8_t light1 = 1;

// varijable za ukljucivanje/iskljucivanje materijala
bool mat0_enabled = true;
bool mat1_enabled = true;

// parametri za materijale
GLfloat mat0[] = {
    0.0, 0.0, 0.5, 1.0, // AMBIENT_AND_DIFFUSE
    0.0, 0.0, 0.0, 0.0, // SPECULAR
    0.0 // SHININESS
};
GLfloat mat1[] = {
    0.0, 0.0, 1.0, 1.0, // AMBIENT_AND_DIFFUSE
    1.0, 1.0, 1.0, 0.0, // SPECULAR
    20.0 // SHININESS
};
GLfloat mat_off[] = {
    0.0, 0.0, 0.0, 0.0, // AMBIENT
    1.0, 1.0, 1.0, 1.0, // DIFFUSE
    0.0, 0.0, 0.0, 0.0, // SPECULAR
    0.0 // SHININESS
};

// GLU objekti za tockove
GLUquadric* tire_quad = NULL;
GLUquadric* rim_quad = NULL;
