#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <GL/glut.h>
double calc(double a) {
    double x = a;
    if ((0 <= x) & (x < 1)) {
        x = (0.5f) * x * x;
        return x;
    }
    if ((1 <= x) & (x < 2)) {
        x = (0.75f) - ((x - (1.5f)) * (x - (1.5f)));
        return x;
    }
    if ((2 <= x) & (x <= 3)) {
        x = (0.5f) * ((3 - x) * (3 - x));
        return x;
    }
    if ((3 < x )) {
        return 0;
    }
    if ((x < 0)) {
        return 0;
    }
}
void display() {
    glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    double vertex[7][2] = {
        {2, 2},
        {1, 4},
        {2, 8},
        {5, 5},
        {7, 7},
        {9, 6},
        {8, 3}
    };

    glPointSize(5.0);
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(2, 2);
    glVertex2f(1, 4);
    glVertex2f(2, 8);
    glVertex2f(5, 5);
    glVertex2f(7, 7);
    glVertex2f(9, 6);
    glVertex2f(8, 3);
    glEnd();

    glColor3f(0,0,0);
    int times = 0;
    double SumX=0;
    double SumY=0;
    glBegin(GL_LINE_STRIP);
    for (double t = 2; t <= 7; t += 0.1) {
        SumX = 0;
        SumY = 0;
        for (int j = 0; j <= 6; j++) {
            SumX += calc(t-j) * vertex[j][0];
            SumY += calc(t-j) * vertex[j][1];
        }
        if (times == 0 || times == 10 || times == 20 || times == 30 || times == 40 || times == 50) {
            printf("t= %.2lf일때 좌표 %.2lf, %.2lf\n", t, SumX, SumY);
        }
        times++;
        glVertex2f(SumX , SumY);
    }
    for (int i = 0; i < 6; i++) {
        printf("직선의 중점 좌표 : %.2f, %.2f\n", (vertex[i][0] + vertex[i + 1][0]) / 2, (vertex[i][1] + vertex[i + 1][1]) / 2);
    }
    glEnd();

    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("6");
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-5,15,-5,15, -1, 1);
    glutMainLoop();
    return(0);
}