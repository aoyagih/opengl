#include <stdio.h>
#include <math.h>
#include <string.h>
#include <OpenGL/opengl.h>
#include <GLUT/GLUT.h>

GLfloat pos0[] = { 2.0, 1.5, -1.0, 1.0 };
GLfloat red[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat green[] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat blue[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat black[] = { .1, .1, .1, 1.0 };
GLfloat gray[] = { 0.3, 0.3, 0.3, 1.0 };

GLfloat train_metal[] = { 0.9, 0.9, 0.9, 1.0 };
GLfloat train_color[] = {(9.0*16.0+9.0)/255.0, (13.0*16.0+13.0)/255.0, 0.0, 1.0 };
GLfloat window_color[] = {188.0/255, 226.0/255, 232.0/255, 1.0 };
GLfloat light_color[] = {1.0, 0.95, 0.5, 1.0 };

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //電車のメインの直方体
    glMaterialfv(GL_FRONT, GL_AMBIENT, train_metal);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialf(GL_FRONT, GL_SHININESS, 10.0);
    glPushMatrix();
    glScalef(1, 1, 4);
    glutSolidCube(1);
    glPopMatrix();
    
    //電車の下の車輪部分
    glMaterialfv(GL_FRONT, GL_AMBIENT, train_metal);
    glPushMatrix();
    glTranslatef(0, -0.5, 0);
    glScalef(0.8, 0.2, 4);
    glutSolidCube(1);
    glPopMatrix();
    
    //上のパンタグラフ×3
    glMaterialfv(GL_FRONT, GL_AMBIENT, black);
    glPushMatrix();
    glScalef(0.05, 1, 1);
    glTranslatef(0, 0.7, 1.5);
    glRotated(45, 1, 0, 0);
    glutWireCube(0.3);
    glPopMatrix();
    
    glPushMatrix();
    glScalef(0.05, 1, 1);
    glTranslatef(0, 0.7, 0.3);
    glRotated(45, 1, 0, 0);
    glutWireCube(0.3);
    glPopMatrix();
    
    glPushMatrix();
    glScalef(0.05, 1, 1);
    glTranslatef(0, 0.7, -1);
    glRotated(45, 1, 0, 0);
    glutWireCube(0.3);
    glPopMatrix();
    
    //電車の帯(上下,前面)
    glMaterialfv(GL_FRONT, GL_AMBIENT, train_color);
    glColor3d((9.0*16.0+9.0)/256.0, (13.0*16.0+13.0)/256.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3d(-0.501, 0.35, 2);
    glVertex3d(-0.501, 0.45, 2);
    glVertex3d(-0.501, 0.45, -2);
    glVertex3d(-0.501, 0.35, -2);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3d(-0.501, -0.2, -2);
    glVertex3d(-0.501, -0.35, -2);
    glVertex3d(-0.501, -0.35, 2);
    glVertex3d(-0.501, -0.2, 2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(-0.4, -0.1, 2.01);
    glVertex3d(-0.4, -0.22, 2.01);
    glVertex3d(0.4, -0.22, 2.01);
    glVertex3d(0.4, -0.1, 2.01);
    glEnd();
    
    
    //前
    glMaterialfv(GL_FRONT, GL_AMBIENT, black);
    glBegin(GL_POLYGON);
    glVertex3d(-0.4, 0.4, 2.01);
    glVertex3d(-0.4, -0.1, 2.01);
    glVertex3d(0.4, -0.1, 2.01);
    glVertex3d(0.4, 0.4, 2.01);
    glEnd();
    
    //前ライト
    glBegin(GL_POLYGON);
    glVertex3d(-0.4, -0.25, 2.01);
    glVertex3d(-0.4, -0.36, 2.01);
    glVertex3d(-0.1, -0.36, 2.01);
    glVertex3d(-0.1, -0.25, 2.01);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3d(0.1, -0.25, 2.01);
    glVertex3d(0.1, -0.36, 2.01);
    glVertex3d(0.4, -0.36, 2.01);
    glVertex3d(0.4, -0.25, 2.01);
    glEnd();
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, light_color);
    glBegin(GL_POLYGON);
    glVertex3d(-0.35, -0.27, 2.02);
    glVertex3d(-0.35, -0.34, 2.02);
    glVertex3d(-0.25, -0.34, 2.02);
    glVertex3d(-0.25, -0.27, 2.02);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3d(0.25, -0.27, 2.02);
    glVertex3d(0.25, -0.34, 2.02);
    glVertex3d(0.35, -0.34, 2.02);
    glVertex3d(0.35, -0.27, 2.02);
    glEnd();
    
    //前窓
    glMaterialfv(GL_FRONT, GL_AMBIENT, window_color);
    //glMaterialfv(GL_FRONT, GL_SPECULAR, black);
    glBegin(GL_POLYGON);
    glVertex3d(-0.38, 0.3, 2.02);
    glVertex3d(-0.38, -0.05, 2.02);
    glVertex3d(0.38, -0.05, 2.02);
    glVertex3d(0.38, 0.3, 2.02);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3d(-0.08, 0.38, 2.02);
    glVertex3d(-0.08, 0.32, 2.02);
    glVertex3d(0.08, 0.32, 2.02);
    glVertex3d(0.08, 0.38, 2.02);
    glEnd();
    
    //横窓
    int i;
    for(i=0; i<4; i++){
        glBegin(GL_POLYGON);
        glVertex3d(-0.501, 0.33, -1.8+i);
        glVertex3d(-0.501, -0.2, -1.8+i);
        glVertex3d(-0.501, -0.2, -1.7+i);
        glVertex3d(-0.501, 0.33, -1.7+i);
        glEnd();
        
        glBegin(GL_POLYGON);
        glVertex3d(-0.501, 0.33, -1.5+i);
        glVertex3d(-0.501, -0.18, -1.5+i);
        glVertex3d(-0.501, -0.18, -1.2+i);
        glVertex3d(-0.501, 0.33, -1.2+i);
        glEnd();
    }
    
    
    glutSwapBuffers();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);    //光源位置の指定
    glLightfv(GL_LIGHT0, GL_POSITION, pos0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, gray);
    glLightfv(GL_LIGHT0, GL_AMBIENT, gray);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //カメラ位置の指定
    gluLookAt(-3.0, 0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Yamanotesen");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
