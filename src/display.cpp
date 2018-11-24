#include "display.h"
#include "data.h"

// crta put
void draw_road()
{
    // ucitava teksturu za put
    static int texture = 0;
    static bool done = false;
    if (!done) {

        glGenTextures(1, (GLuint *) &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, gimp_image.width, gimp_image.height,
            0, GL_RGBA, GL_UNSIGNED_BYTE, gimp_image.pixel_data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        done = true;

    } else {

        glBindTexture(GL_TEXTURE_2D, texture);

    }
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glEnable(GL_TEXTURE_2D);

    // crta put
    glPushMatrix();
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glTranslatef(0.0f, -2.0f, 0.7f);
        glBegin(GL_POLYGON);
            glTexCoord2f(0.0f, 1.0f); glVertex2f(-3.0f, 15.0f);
            glTexCoord2f(0.0f, 0.0f); glVertex2f(3.0f, 15.0f);
            glTexCoord2f(1.0f, 0.0f); glVertex2f(3.0f, -15.0f);
            glTexCoord2f(1.0f, 1.0f); glVertex2f(-3.0f, -15.0f);
        glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

// crta desni tocak
void draw_right_wheel()
{
    glPushMatrix();
        // animacija sa rotacijom
        glRotatef(direction ? angle : -angle, 0.0f, 0.0f, 1.0f);
        gluCylinder(tire_quad, 0.8, 0.8, 0.5, 10, 10);
        gluDisk(rim_quad, 0.0, 0.8, 10, 10);
    glPopMatrix();
}

// crta lijevi tocak
void draw_left_wheel()
{
    glPushMatrix();
        // animacija sa rotacijom
        glRotatef(direction ? angle : -angle, 0.0f, 0.0f, 1.0f);
        gluCylinder(tire_quad, 0.8, 0.8, 0.5, 10, 10);
        glTranslatef(0.0f, 0.0f, 0.5f);
        gluDisk(rim_quad, 0.0, 0.8, 10, 10);
    glPopMatrix();
}

void set_mat0()
{
    if (mat0_enabled) {
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, &mat0[0]);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, &mat0[4]);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &mat0[8]);
    } else {
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, &mat_off[0]);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, &mat_off[4]);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, &mat_off[8]);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &mat_off[12]);
    }
}

void set_mat1()
{
    if (mat1_enabled) {
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, &mat1[0]);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, &mat1[4]);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &mat1[8]);
    } else {
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, &mat_off[0]);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, &mat_off[4]);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, &mat_off[8]);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &mat_off[12]);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // postavlja kameru
    switch (camera) {
    case 0:
        gluLookAt(-5.0, 3.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        break;
    case 1:
        gluLookAt(10.0, 10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        break;
    }

    // animacija sa skaliranjem
    glScalef(scale_factor, scale_factor, scale_factor);

    // crta put
    draw_road();

    // animacija sa translacijom
    glTranslatef(0.0f, 0.0f, position);

    // crta tijelo auta
    set_mat0();
    glPushMatrix();
        glScalef(2.0f, 1.0f, 4.0f);
        glutSolidCube(1.0);
    glPopMatrix();

    // crta tockove
    set_mat1();
    glPushMatrix();
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        glTranslatef(-1.0f, 0.0f, -1.5f);
        draw_right_wheel();
        glTranslatef(0.0f, 0.0f, 2.5f);
        draw_left_wheel();
        glTranslatef(2.0f, 0.0f, 0.0f);
        draw_left_wheel();
        glTranslatef(0.0f, 0.0f, -2.5f);
        draw_right_wheel();
    glPopMatrix();

    glutSwapBuffers();
}
