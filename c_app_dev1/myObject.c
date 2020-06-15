#include <stdio.h>
#include <math.h>
#include <string.h>
#include <OpenGL/opengl.h>
#include <GLUT/GLUT.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3d(0.6, 0.6, 0.6);

    //電車のメインの直方体
    glPushMatrix();
    glScalef(1, 1, 4);
    glutSolidCube(1);
    glPopMatrix();
    
    //上のパンタグラフ×3
    glColor3d(0, 0, 0);
    glPushMatrix();
    glScalef(0.05, 1, 1);
    glTranslatef(0, 0.65, 1.5);
    glRotated(45, 1, 0, 0);
    glutWireCube(0.3);
    glPopMatrix();
    
    glPushMatrix();
    glScalef(0.05, 1, 1);
    glTranslatef(0, 0.65, 0.3);
    glRotated(45, 1, 0, 0);
    glutWireCube(0.3);
    glPopMatrix();
    
    glPushMatrix();
    glScalef(0.05, 1, 1);
    glTranslatef(0, 0.65, -1);
    glRotated(45, 1, 0, 0);
    glutWireCube(0.3);
    glPopMatrix();
    
    //電車の帯(上下,前面)
    glColor3d((9.0*16.0+9.0)/256.0, (13.0*16.0+13.0)/256.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3d(-0.501, 0.3, 2);
    glVertex3d(-0.501, 0.45, 2);
    glVertex3d(-0.501, 0.45, -2);
    glVertex3d(-0.501, 0.3, -2);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3d(-0.501, -0.25, 2);
    glVertex3d(-0.501, -0.4, 2);
    glVertex3d(-0.501, -0.4, -2);
    glVertex3d(-0.501, -0.25, -2);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3d(-0.45, -0.25, 2);
    glVertex3d(-0.45, -0.4, 2);
    glVertex3d(0.45, -0.4, 2);
    glVertex3d(0.45, -0.25, 2);
    glEnd();
    //窓
    glColor3d(0, 0, 0);
    
    glBegin(GL_POLYGON);
    glVertex3d(-0.45, 0.45, 2);
    glVertex3d(-0.45, -0.2, 2);
    glVertex3d(0.45, -0.2, 2);
    glVertex3d(0.45, 0.45, 2);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3d(-0.501, 0.25, 0.2);
    glVertex3d(-0.501, -0.2, 0.2);
    glVertex3d(-0.501, -0.2, 0);
    glVertex3d(-0.501, 0.25, 0);
    glEnd();
    
    glutSwapBuffers();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_FRONT);
    //glCullFace(GL_BACK);

    //glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHT1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, 1, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-3.0, 1.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_RGBA);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Yamanote Line");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
