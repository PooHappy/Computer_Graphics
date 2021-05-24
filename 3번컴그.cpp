#include <windows.h> // use proper includes for your system
#include <math.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/Glut.h>
const int screenWidth = 480;	   // width of the screen window in pixels 
const int screenHeight = 480;	   // height of the screen window in pixels
#define PI 3.141592
#define TWOPI 2*3.141592

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);       // the background color is white
	glColor3f(0.0f, 0.0f, 0.0f);         // the drawing color is black 
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20, 120, -20, 120);

}
void drdisc(float r, float x, float y) {
	glBegin(GL_TRIANGLE_FAN);
	int N = 1000;
	float a; float b;

	for (float i = 0; i <= 2 * PI; i += PI / N) {
		a = x + r * cos(i);
		b = y + r * sin(i);
		glVertex2f(a, b);
	}
	glEnd();
}
void ellipse(float r, float x, float y) {
	glBegin(GL_TRIANGLE_FAN);
	int N = 1000;
	float a; float b;
	glColor3f(0, 0, 0);
	for (float i = 0; i <= 2 * PI; i += PI / N) {
		a = pow(sqrt(r)+1,2) * cos(i);
		b = r * sin(i);
		glVertex2f(x + a, y + b);
	}
	glEnd();
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	//glBegin(GL_TRIANGLE_FAN);
	//빨간색 + 흰색 원
	/*
	glColor3f(1, 0, 0);
	drdisc(20, 25, 75);
	glColor3f(1, 1, 1);
	drdisc(10, 25, 75);
	*/

	//검은색 타원 + 흰색 원
	ellipse(20, 25, 75);
	glColor3f(1, 1, 1);
	drdisc(20, 25, 75);
	ellipse(10, 25, 75);
	glColor3f(1, 1, 1);
	drdisc(10, 25, 75);
	glFlush();
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode
	glutInitWindowSize(screenWidth, screenHeight); // set the window size
	glutInitWindowPosition(200, 200); // set the window position on screen
	glutCreateWindow("Dot Plot of a Function"); // open the screen window
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}
//컴그 1번