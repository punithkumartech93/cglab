#include<GL/glut.h>
#include<stdlib.h>
GLfloat vertices[8][3]={{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1},{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1}};
GLfloat Color[8][3]={{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};

static GLfloat theta[]={0,0,0};
static GLint axis=2;
static GLdouble viewer[]={0,0,5};

void polygon(int a,int b,int c,int d)
{
glBegin(GL_POLYGON);
glColor3fv(Color[a]);
glVertex3fv(vertices[a]);
glColor3fv(Color[b]);
glVertex3fv(vertices[b]);
glColor3fv(Color[c]);
glVertex3fv(vertices[c]);
glColor3fv(Color[d]);
glVertex3fv(vertices[d]);
glEnd();
}

void colorcube()
{
polygon(0,3,2,1);
polygon(2,3,7,6);
polygon(1,2,6,5);
polygon(0,4,5,1);
polygon(4,5,6,7);
polygon(0,3,7,4);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(viewer[0],viewer[1],viewer[2],0,0,0,0,1,0);
glRotatef(theta[0],1,0,0);
glRotatef(theta[1],0,1,0);
glRotatef(theta[2],0,0,1);
colorcube();
glFlush();
glutSwapBuffers();
}

/*void spincube()
{
theta[axis]+=2.0;
if(theta[axis]>360)
theta[axis]-=360;
glutPostRedisplay();
}*/

void mymouse(int btn,int state,int x,int y)
{
gluLookAt(0,10,5,0,0,0,0,1,0);
if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
axis=0;
if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
axis=1;
if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
axis=2;
theta[axis]+=2.0;
if(theta[axis]>360)
theta[axis]-=360;
display();
}

void keys(unsigned char key,int x,int y)
{
if(key=='a') viewer[0]-=1;
if(key=='A') viewer[0]+=1;
if(key=='b') viewer[1]-=1;
if(key=='B') viewer[1]+=1;
if(key=='c') viewer[2]-=1;
if(key=='C') viewer[2]+=1;
display();
}

void myreshape(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(w<=h)
glFrustum(-2,2,-2*(GLfloat)h/(GLfloat)w,2*(GLfloat)h/(GLfloat)w,2,20);
else
glFrustum(-2*(GLfloat)w/(GLfloat)h,2*(GLfloat)w/(GLfloat)h,-2,2,2,20);
glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutCreateWindow("cube");
glutReshapeFunc(myreshape);
glutDisplayFunc(display);
//glutIdleFunc(spincube);
glutKeyboardFunc(keys);
glutMouseFunc(mymouse);
glEnable(GL_DEPTH_TEST);
glClearColor(1,1,1,1);
glutMainLoop();
}
