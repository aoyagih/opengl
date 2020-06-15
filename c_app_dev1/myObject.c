#include <stdio.h>
#include <OpenGL/opengl.h>
#include <GLUT/GLUT.h>

//光源の位置
GLfloat pos0[] = { 2.0, 1.5, -1.0, 1.0 };
//色
GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat black[] = { .1, .1, .1, 1.0 };
GLfloat gray[] = { 0.3, 0.3, 0.3, 1.0 };
GLfloat body_color[] = { 0.9, 0.9, 0.9, 1.0 };                                     //車体の色
GLfloat line_color[] = {(9.0*16.0+9.0)/255.0, (13.0*16.0+13.0)/255.0, 0.0, 1.0 };  //電車の帯の色
GLfloat window_color[] = {188.0/255, 226.0/255, 232.0/255, 1.0 };                  //車窓の色
GLfloat light_color[] = {1.0, 0.95, 0.5, 1.0 };                                    //電車のライトの色

int i;

void displayBody(void){
    //電車のメインの直方体
    glMaterialfv(GL_FRONT, GL_AMBIENT, body_color);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialf(GL_FRONT, GL_SHININESS, 10.0);
    glPushMatrix();
    glScalef(1, 1, 4);
    glutSolidCube(1);
    glPopMatrix();
    
    //電車の下の車輪部分
    glPushMatrix();
    glTranslatef(0, -0.5, 0);
    glScalef(0.8, 0.2, 4);
    glutSolidCube(1);
    glPopMatrix();
}

void displayPantograph(void){
    //上のパンタグラフ×3
    glMaterialfv(GL_FRONT, GL_AMBIENT, black);
    for(i=0; i<3; i++){
        glPushMatrix();
        glScalef(0.05, 1, 1);
        glTranslatef(0, 0.7, -1.0+1.2*i);
        glRotated(45, 1, 0, 0);
        glutWireCube(0.3);
        glPopMatrix();
    }
}

void displayFront(void){
    //上の黒い部分
    glMaterialfv(GL_FRONT, GL_AMBIENT, black);
    glBegin(GL_POLYGON);
    glVertex3d(-0.4, 0.4, 2.01);
    glVertex3d(-0.4, -0.1, 2.01);
    glVertex3d(0.4, -0.1, 2.01);
    glVertex3d(0.4, 0.4, 2.01);
    glEnd();
    
    //帯
    glMaterialfv(GL_FRONT, GL_AMBIENT, line_color);
    glBegin(GL_POLYGON);
    glVertex3d(-0.4, -0.1, 2.01);
    glVertex3d(-0.4, -0.22, 2.01);
    glVertex3d(0.4, -0.22, 2.01);
    glVertex3d(0.4, -0.1, 2.01);
    glEnd();
    
    //ライト
    glMaterialfv(GL_FRONT, GL_AMBIENT, black);
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
    
    //窓
    glMaterialfv(GL_FRONT, GL_AMBIENT, window_color);
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
    
}

void displaySide(void){
    //電車の帯(上,下)
    glMaterialfv(GL_FRONT, GL_AMBIENT, line_color);
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
    
    //窓
    glMaterialfv(GL_FRONT, GL_AMBIENT, window_color);
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
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    displayBody();           //車体の描画
    displayPantograph();     //パンタグラフの描画
    displayFront();          //前面の描画
    displaySide();           //側面の描画
    
    glutSwapBuffers();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //光源位置の指定
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
