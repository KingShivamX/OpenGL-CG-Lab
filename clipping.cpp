#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>
using namespace std;
float xmin = -100;
float ymin = -100;
float xmax = 100;
float ymax = 100;
typedef struct points {
    float x, y;
    int CODE[4];
}PT;
PT p1, p2, p3, p4;
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glPointSize(2.5);
    gluOrtho2D(-300, 1024, -300, 768);
}
void setCode(PT& point)
{
    if (point.x < xmin)
        point.CODE[3] = 1;
    else
        point.CODE[3] = 0;
    if (point.x > xmax)
        point.CODE[2] = 1;
    else
        point.CODE[2] = 0;
    if (point.y < ymin)
        point.CODE[1] = 1;
    else
        point.CODE[1] = 0;
    if (point.y > ymax)
        point.CODE[0] = 1;
    else
        point.CODE[0] = 0;
}
int setVisible(PT p1, PT p2) {
    int flag = 1;
    PT ptemp;
    for (int i = 0; i < 4; i++)
        if (p1.CODE[i] != 0 || p2.CODE[i] != 0)
            flag = 0;
    if (flag)
        return 0;
    else {
        for (int i = 0; i < 4; i++) {
            if (p1.CODE[i] == 1 && p2.CODE[i] == 1)
                ptemp.CODE[i] = 1;
            else
                ptemp.CODE[i] = 0;
        }
        for (int i = 0; i < 4; i++) {
            if (ptemp.CODE[i] == 1) {
                flag = 1;
            }
        }
        if (flag)
            return 1;
        else
            return 2;
    }
}
PT pointIntersetion(PT point, float m) {
    float x, y;
    x = point.x;
    y = point.y;
    if (point.CODE[3] == 1) {
        x = xmin;
        y = m * (x - point.x) + point.y;
    }
    if (point.CODE[2] == 1) {
        x = xmax;
        y = m * (x - point.x) + point.y;
    }
    if (point.CODE[1] == 1) {
        y = ymin;
        x = point.x + (y - point.y) / m;
    }
    if (point.CODE[0] == 1) {
        y = ymax;
        x = point.x + (y - point.y) / m;
    }
    point.x = x;
    point.y = y;
    return point;
}
void cohen_Line(PT p1, PT p2)
{
    PT ptemp;
    setCode(p1);
    setCode(p2);
    switch (setVisible(p1, p2)) {
    case 0:
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(xmin + 500, ymin + 500);
        glVertex2f(xmin + 500, ymax + 500);
        glVertex2f(xmax + 500, ymax + 500);
        glVertex2f(xmax + 500, ymin + 500);
        glEnd();
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex2f(p1.x + 500, p1.y + 500);
        glVertex2f(p2.x + 500, p2.y + 500);
        glEnd();
        glFlush();
        break;
    case 1:
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(xmin + 500, ymin + 500);
        glVertex2f(xmin + 500, ymax + 500);
        glVertex2f(xmax + 500, ymax + 500);
        glVertex2f(xmax + 500, ymin + 500);
        glEnd();
        glFlush();
        break;
    case 2:
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(xmin + 500, ymin + 500);
        glVertex2f(xmin + 500, ymax + 500);
        glVertex2f(xmax + 500, ymax + 500);
        glVertex2f(xmax + 500, ymin + 500);
        glEnd();
        float m;
        m = (p1.y - p2.y) / (p1.x - p2.x);
        glColor3f(1.0, 0.0, 0.0);
        p1 = pointIntersetion(p1, m);
        p2 = pointIntersetion(p2, m);
        setCode(p1);
        setCode(p2);
        if (setVisible(p1, p2) == 0) {
            glBegin(GL_LINES);
            glVertex2f(p1.x + 500, p1.y + 500);
            glVertex2f(p2.x + 500, p2.y + 500);
            glEnd();
        }
        glFlush();
        break;
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmin, ymax);
    glVertex2f(xmax, ymax);
    glVertex2f(xmax, ymin);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glVertex2f(p3.x, p3.y);
    glVertex2f(p4.x, p4.y);
    glEnd();
    cohen_Line(p1, p2);
    cohen_Line(p3, p4);
    glFlush();
}
int main(int argc, char** argv)
{
    printf("Enter line - 1 co-ordinates:");
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    printf("Enter line - 2 co-ordinates:");
    cin >> p3.x >> p3.y >> p4.x >> p4.y;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Clipping");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}


//- 200 100 150 300
//- 100 - 200 100 100