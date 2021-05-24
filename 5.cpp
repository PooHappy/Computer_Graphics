#include <GL/glut.h>
static float t = 1.0;
void DoTimer(int value)
{
    t += 0.1;
    glutPostRedisplay();
    glutTimerFunc(30, DoTimer, 1);
}

void init(void)
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };

    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void drawScene()
{
    glFrustum(-5, 5, -5, 5, 5, 50);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(15, 15, 15, 0, 0, 0, 0.0, 1, 0.0);

    glBegin(GL_POLYGON);
    glVertex3f(-5, -15, 15);
    glVertex3f(0, -20, 15);
    glVertex3f(2, 12, -15);
    glVertex3f(-5, 13, -15);
    glEnd();

    glTranslatef(0, 12 - t * t, -12 + t * t);
    glutSolidSphere(3.0, 100, 10);

    glutSwapBuffers();
}


int main()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("5");
    init();
    glutDisplayFunc(drawScene);
    glutTimerFunc(30, DoTimer, 1);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glutMainLoop();
    return 0;

}