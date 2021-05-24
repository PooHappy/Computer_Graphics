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
	gluOrtho2D(0, 1, 0, 1);

}
void tilling() {
	glBegin(GL_LINE_STRIP);
	int N = 1000;
	for (float x = 0; x <= PI/2; x += PI / N) {
		glVertex2f(cos(x), sin(x));
	}
	for (float x = PI * 1.5; x <= TWOPI; x += PI / N) {
		glVertex2f(cos(x), 1 + sin(x));
	}
	for (float x = PI; x <= PI * 1.5; x += PI / N) {
		glVertex2f(1 + cos(x), 1 + sin(x));
	}
	for (float x = PI/2; x <= PI; x += PI / N) {
		glVertex2f(1 + cos(x), sin(x));
	}
	glEnd();
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	//tilling();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++){
			glViewport(i*120, j*120, 120, 120);
			tilling();
		}
	}
	glFlush();		   // send all output to display 
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode
	glutInitWindowSize(screenWidth, screenHeight); // set the window size
	glutInitWindowPosition(0, 0); // set the window position on screen
	glutCreateWindow("Dot Plot of a Function"); // open the screen window
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}