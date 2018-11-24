#include "init.h"
#include "data.h"

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glShadeModel(GL_FLAT);

    // prvi izvor svjetlosti
    GLfloat light0_position[] = { 25.0f, 50.0f, 50.0f, 0.0f };
    GLfloat light0_color[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_color);

    // drugi izvor svjetlosti
    GLfloat light1_position[] = { -25.0f, 50.0f, -50.0f, 0.0f };
    GLfloat light1_color[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_color);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);

    // kreira potrebne objekte za tockove
    tire_quad = gluNewQuadric();
    rim_quad = gluNewQuadric();
    gluQuadricNormals(tire_quad, GLU_SMOOTH);
    gluQuadricNormals(rim_quad, GLU_SMOOTH);

    // podesava projekciju
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1.0, 2.5, 30.0);
}
