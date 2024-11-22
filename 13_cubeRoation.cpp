#include <GL/glut.h>
#include<math.h>

GLfloat d=0;

void MyInit()
{
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);//To see back faces, activate z buffer
}
void Spin()
{
    d=d+0.01;
    if (d>360)
        d=0;
    glutPostRedisplay();
}

void Face(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[])
{
    glBegin(GL_POLYGON);
        glVertex3fv(A);
        glVertex3fv(B);
        glVertex3fv(C);
        glVertex3fv(D);
    glEnd();
}

void Cube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], GLfloat V5[], GLfloat V6[], GLfloat V7[])
{
    glColor3f(1,0,0);
    Face(V0,V1,V2,V3); //Front Face
    glColor3f(0,1,0);
    Face(V4,V5,V6,V7);//Back Face
    glColor3f(0,0,1);
    Face(V0,V4,V7,V3);//Left Face
    glColor3f(1,1,0);
    Face(V1,V5,V6,V2);//Right Face
    glColor3f(1,0,1);
    Face(V2,V3,V7,V6);//Bottom Face
    glColor3f(0,1,1);
    Face(V0,V1,V5,V4);//Top Face
}

void Draw()
{
    GLfloat V[8][3]= {
        {-0.5,0.5,0.5},
        {0.5,0.5,0.5},
        {0.5,-0.5,0.5},
        {-0.5,-0.5,0.5},

        {-0.5,0.5,-0.5},
        {0.5,0.5,-0.5},
        {0.5,-0.5,-0.5},
        {-0.5,-0.5,-0.5}
    };
    GLfloat rV[8][3],r;
    int i, a=2;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    r=d*3.14/180;
    if(a == 1)
    {
        for(i=0;i<8;i++)
        {
            rV[i][1]=V[i][1]*cos(r)-V[i][2]*sin(r);
            rV[i][2]=V[i][1]*sin(r)+V[i][2]*cos(r);
            rV[i][0]=V[i][0];
        }
    }

    if (a== 2)
    {
        for(i=0;i<8;i++)
        {
            rV[i][2] = V[i][2]*cos(r)-V[i][0]*sin(r);
            rV[i][1]= V[i][1];
            rV[i][0] = V[i][2]*sin(r)+V[i][0]*cos(r);
        }
    }

    if (a == 3)
    {
        for( i = 0; i < 8 ;i++)
        {
            rV[i][0]=V[i][0]*cos(r)-V[i][1]*sin(r);
            rV[i][1]=V[i][0]*sin(r)+V[i][1]*cos(r);
            rV[i][2]=V[i][2];
        }
    }

    Cube (rV[0],rV[1],rV[2],rV[3],rV[4],rV[5],rV[6],rV[7]);
    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(50,150);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("CUBE SPIN");
    MyInit();
    glutDisplayFunc (Draw);
    glutIdleFunc(Spin);
    glutMainLoop();
    return 0;
}




//  3D cube



#include<GL/glut.h>
#include<math.h>

GLfloat d = 0, d2 = 0;

void MyInit()
{
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
}

void Spin()
{
    d = d+0.02;
    d2 = d2+0.10;
    if(d>360)
        d = 0;
        if(d>360)
            d2 = 0;
    glutPostRedisplay();
}

void Face(GLfloat A[],GLfloat B[],GLfloat C[],GLfloat D[])
{
    glBegin(GL_POLYGON);
    glVertex3fv(A);
    glVertex3fv(B);
    glVertex3fv(C);
    glVertex3fv(D);
    glEnd();
}

void Cube(GLfloat V0[],GLfloat V1[],GLfloat V2[],GLfloat V3[],GLfloat V4[],GLfloat V5[],GLfloat V6[],GLfloat V7[])
{
    glColor3f(1, 0.5, 0);
    Face(V0, V1, V2, V3);
    glColor3f(1, 0.5, 0);
    Face(V4, V5, V6, V7);
    glColor3f(0, 0, 1);
    Face(V0, V4, V7, V3);
    glColor3f(1, 1, 0);
    Face(V1, V5, V6, V2);
    glColor3f(1, 0, 1);
    Face(V2, V3, V7, V6);
    glColor3f(0, 1, 1);
    Face(V0, V1, V5, V4);
}

void Draw()
{
   GLfloat V[8][3]= {
                        {-0.5, 0.5, 0.5},
                        {0.5, 0.5, 0.5},
                        {0.5, -0.5, 0.5},
                        {-0.5, -0.5, 0.5},

                        {-0.5, 0.5, -0.5},
                        {0.5, 0.5, -0.5},
                        {0.5, -0.5, -0.5},
                        {-0.5, -0.5, -0.5}
                    };
   GLfloat rV[8][3], r1, r2;
   int i, a=3;

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   r1 = d*3.14/180;
   r2 = d2*3.14/180;

   for(i = 0; i < 8; i++)
   {
       // First, rotate around the x-axis
       rV[i][1] = V[i][1] * cos(r1) - V[i][2] * sin(r1);
       rV[i][2] = V[i][1] * sin(r1) + V[i][2] * cos(r1);
       rV[i][0] = V[i][0];

       // Then rotate around the y-axis
       GLfloat temp = rV[i][0];
       rV[i][0] = rV[i][0] * cos(r2) - rV[i][2] * sin(r2);
       rV[i][2] = temp * sin(r2) + rV[i][2] * cos(r2);
   }

   Cube(rV[0], rV[1], rV[2], rV[3], rV[4], rV[5], rV[6], rV[7]);

   glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100,150);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("CUBE SPIN");
    MyInit();
    glutDisplayFunc(Draw);
    glutIdleFunc(Spin);
    glutMainLoop();
    return 0;
}