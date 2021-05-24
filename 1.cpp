#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <GL/glut.h>

using namespace std;

void display()
{
    glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluLookAt(5, 5, 5, 0, 0, 0, 0.0, 1, 0.0);

    float vertex[10][3];
    float normal[7][3];
    float face[7][5];
    vector<float> arrV = { 0,0,0,1,0,0,1,1,0,0.5,1.5,0,0,1,0,0,0,1,1,0,1,1,1,1,0.5,1.5,1,0,1,1 };
    vector<float> arrN = { -1,0,0, -0.707,0.707,0 ,0.707,0.707,0 ,1,0,0 ,0,-1,0 ,0,0,1 ,0,0,-1 };
    vector<float> arrF = { 0,5,9,4,3,4,9,8,2,3,8,7,1,2,7,6,0,1,6,5,5,6,7,8,9,0,4,3,2,1 };
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            vertex[i][j] = arrV.at(j + count);
        }
        count += 3;
    }
    count = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            normal[i][j] = arrN.at(j + count);
        }
        count += 3;
    }
    count = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            face[i][j] = arrF.at(j + count);
        }
        count += 4;
    }
    for (int i = 5; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
            face[i][j] = arrF.at(j + count);
        }
        count += 5;
    }
    
    glColor3f(1, 1, 0);
    for (int i = 0; i < 5; i++) {
        glBegin(GL_POLYGON);
        for (int j = 0; j < 4; j++) {
            int pos = face[i][j];
            glVertex3f(vertex[pos][0], vertex[pos][1], vertex[pos][2]);
        }
        glEnd();
    }
    for (int i = 5; i < 7; i++) {
        glBegin(GL_POLYGON);
        for (int j = 0; j < 5; j++) {
            int pos = face[i][j];
            glVertex3f(vertex[pos][0], vertex[pos][1], vertex[pos][2]);
        }
        glEnd();
    }
    glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("1");
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);
    glFrustum(-2, 2, -2, 2, 5, 10);
    glutMainLoop();
    return(0);
}