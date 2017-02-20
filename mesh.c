#include<stdio.h>
#include<stdio.h>
#include<GL/glut.h>

#define dx 10
#define dy 10
GLfloat R=0.0,G=0.0,B=0.0,BR=1,BG=1,BB=1;
void display()
{
GLint i,j;
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(R,G,B);
for(i=10;i<300;i+=dx)
for(j=10;j<300;j+=dy)
{
glBegin(GL_LINE_LOOP);
glVertex2i(i,j);
glVertex2i(i+dx,j);
glVertex2i(i+dx,j+dy);
glVertex2i(i,j+dy);
glEnd();
}
glFlush();
}

int main(int argc,char **argv)
{
printf("Enter the R G B color values\n");
scanf("%f %f %f",&R,&G,&B);
printf("Enter the BR BG BB color values\n");
scanf("%f %f %f",&BR,&BG,&BB);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,50);
glutInitWindowSize(800,800);
glutCreateWindow("sample");
glClearColor(BR,BG,BB,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,500,0.0,500);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
