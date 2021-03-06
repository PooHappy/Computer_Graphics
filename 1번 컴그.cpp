#include <windows.h> // use proper includes for your system
#include <math.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/Glut.h>
const int screenWidth = 400;	   // width of the screen window in pixels 
const int screenHeight = 200;	   // height of the screen window in pixels
#define PI 3.141592
#define TWOPI 2*3.141592

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);       // the background color is white
	glColor3f(0.0f, 0.0f, 0.0f);         // the drawing color is black 
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 4.0, -1.0, 1.0);

}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 

	glBegin(GL_LINE_STRIP);
	for (float x = 0; x <= 4.0; x = x + 0.005)
	{
		double func = exp(-x) * cos(2 * PI * x);
		glVertex2f(x, func);
	}
	glEnd();
	glFlush();		   // send all output to display 
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode
	glutInitWindowSize(screenWidth, screenHeight); // set the window size
	glutInitWindowPosition(100, 150); // set the window position on screen
	glutCreateWindow("Dot Plot of a Function"); // open the screen window
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}