#include<GL/glut.h>
void traingle()
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINE_LOOP);

glVertex2i(10,10);
glColor3f(1,0,0);
glVertex2i(10,10);
glColor3f(1,0,0);
glVertex2i(100,10);
glColor3f(1,0,0);
glVertex2i(50,100);
glColor3f(1,0,0);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2i(25,50);
glVertex2i(78,50);
glVertex2i(50,10);
glEnd();
glFlush();
}

int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,50);
glutInitWindowSize(800,800);
glutCreateWindow("sample");
glClearColor(1.0,1.0,1.0,1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,500,0,500);
glutDisplayFunc(traingle);
glutMainLoop();
return 0;
}
