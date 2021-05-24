#include <cstdlib>
#include <cmath>
#include <GL/glut.h>

void display() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_BLEND);
	//glEnable(GL_DEPTH_TEST); 
	glClear(GL_DEPTH_BUFFER_BIT);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	/*
	glBegin(GL_POLYGON);
	glColor4f(1, 0, 0, 0.5);
	glVertex3f(1, -1, 0);
	glVertex3f(2, -1, 0);
	glVertex3f(2, 3, 0);
	glVertex3f(1, 3, 0);
	glEnd();*/
	
	glBegin(GL_POLYGON);
	glColor4f(0, 0, 1, 0.5);
	glVertex3f(-1, 0, 0);
	glVertex3f(3, 0, 0);
	glVertex3f(3, 1, 0);
	glVertex3f(-1, 1, 0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor4f(1, 0, 0, 0.5);
	glVertex3f(1, -1, 0);
	glVertex3f(2, -1, 0);
	glVertex3f(2, 3, 0);
	glVertex3f(1, 3, 0);
	glEnd();

	glFlush();

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutCreateWindow(argv[0]);
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 4, -2, 4, -1, 1);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}