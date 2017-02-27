#include<GL/glut.h>
#include<stdio.h>
typedef float point[3];
point v[]={{0.0,0.0,1.0},{0.0,1.0,0.0},{-1.0,-0.5,0.0},{1.0,-0.5,0.0}};
int n;
void triangle(point a,point b,point c)
{
glBegin(GL_POLYGON);
glVertex3fv(a);
glVertex3fv(b);
glVertex3fv(c);
glEnd();
}
void divide(point a,point b,point c,int m)
{
point v1,v2,v3;
int j;
if(m>0)
{
for(j=0;j<3;j++) v1[j]=(a[j]+b[j])/2;
for(j=0;j<3;j++) v2[j]=(a[j]+c[j])/2;
for(j=0;j<3;j++) v3[j]=(b[j]+c[j])/2;
divide(a,v1,v2,m-1);
divide(c,v2,v3,m-1);
divide(b,v3,v1,m-1);
}
else(triangle(a,b,c));
}
void tetra(int m)
{
glColor3f(1.0,0.0,0.0);
divide(v[0],v[1],v[2],m);

glColor3f(0.0,1.0,0.0);
divide(v[3],v[2],v[1],m);

glColor3f(0.0,0.0,1.0);
divide(v[0],v[3],v[1],m);

glColor3f(1.0,1.0,1.0);
divide(v[0],v[2],v[3],m);
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
tetra(n);
glFlush();
}
void myReshape(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-2,2,-2,2,-2,2);
glMatrixMode(GL_MODELVIEW);
glutPostRedisplay();
}
int main(int argc,char **argv)
{
printf("enter no of divisions\n");
scanf("%d",&n);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
glutCreateWindow("3d gasket");
glutReshapeFunc(myReshape);
glutDisplayFunc(display);
glEnable(GL_DEPTH_TEST);
glClearColor(0.0,0.0,0.0,0.0);
glutMainLoop();
}
