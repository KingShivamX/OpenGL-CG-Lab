#include <GL/glut.h>

void init(){
    glClearColor(0.1, 0.1, 0.1, 1.0);  // Dark background
    gluOrtho2D(-300, 300, -300, 300);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    // Borders with gradient color
    glBegin(GL_LINES);
        glColor3f(0.6, 0.2, 0.8);  // Purple color
        glVertex2i(-100, 300);
        glVertex2i(-100, -100);

        glColor3f(0.2, 0.8, 0.6);  // Teal color
        glVertex2i(100, 100);
        glVertex2i(100, -300);

        glColor3f(0.8, 0.6, 0.2);  // Orange color
        glVertex2i(-300, 100);
        glVertex2i(100, 100);

        glColor3f(0.2, 0.6, 0.8);  // Blue color
        glVertex2i(-100, -100);
        glVertex2i(300, -100);
    glEnd();

    // Corners with bright color
    glPointSize(8);
    glBegin(GL_POINTS);
        glColor3f(1, 0.5, 0);  // Bright orange
        glVertex2i(-100, 100);
        glVertex2i(100, -100);
    glEnd();

    // Operators with vibrant colors

    // Plus
    glBegin(GL_POLYGON);
        glColor3f(1, 0, 0.5);  // Vibrant pink
        glVertex2i(-210, 210);
        glVertex2i(-210, 250);
        glVertex2i(-190, 250);
        glVertex2i(-190, 210);
        glVertex2i(-150, 210);
        glVertex2i(-150, 190);
        glVertex2i(-190, 190);
        glVertex2i(-190, 150);
        glVertex2i(-210, 150);
        glVertex2i(-210, 190);
        glVertex2i(-250, 190);
        glVertex2i(-250, 210);
    glEnd();

    // Minus
    glBegin(GL_POLYGON);
        glColor3f(0, 0.8, 1);  // Bright cyan
        glVertex2i(-50, -10);
        glVertex2i(50, -10);
        glVertex2i(50, 10);
        glVertex2i(-50, 10);
    glEnd();

    // X
    glBegin(GL_POLYGON);
        glColor3f(0.8, 0.4, 0);  // Deep orange
        glVertex2i(186, -200);
        glVertex2i(158, -172);
        glVertex2i(172, -158);
        glVertex2i(200, -186);
        glVertex2i(228, -158);
        glVertex2i(242, -172);
        glVertex2i(214, -200);
        glVertex2i(242, -228);
        glVertex2i(228, -242);
        glVertex2i(200, -214);
        glVertex2i(172, -242);
        glVertex2i(158, -228);
    glEnd();

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("berij vajabaaki gunakar");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
