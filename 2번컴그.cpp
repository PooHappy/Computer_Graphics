#include <GL/glut.h>
#include <math.h>
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(0, 0, 1, 1);// to be explained
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glShadeModel(GL_FLAT);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-0.1,0.3);
	glColor3f(0, 1, 0);
	glVertex2f(-0.1,0.4);
	glColor3f(0, 0, 1);
	glVertex2f(0.0,0.3);
	glColor3f(0, 1, 0);
	glVertex2f(0.1,0.4);
	glColor3f(0, 0, 1);
	glVertex2f(0,0);
	glColor3f(0, 1, 0);
	glVertex2f(0.1,0.1);
	glColor3f(0, 0, 1);
	glVertex2f(0.3,0);
	glColor3f(0, 1, 0);
	glVertex2f(0.2,0.1);
	glColor3f(0, 0, 1);
	glVertex2f(0.3,0.3);
	glColor3f(0, 1, 0);
	glVertex2f(0.2,0.4);
	glColor3f(0, 0, 1);
	glVertex2f(0.4,0.3);
	glColor3f(0, 1, 0);
	glVertex2f(0.4,0.4);
	glEnd();
	glFlush();		                 // send all output to display 
}
void main(int argc, char** argv)
{
	glutInitWindowSize(500, 500);     // set the window size
	glutInitWindowPosition(20, 20); // set the window position on the screen
	glutCreateWindow("my first attempt"); // open the screen window(with its exciting title)
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}