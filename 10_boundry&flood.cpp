#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>
#include <cmath>

using namespace std;

class poly {
public:
    poly() {
        // Initialize GLUT window
        glutInitWindowSize(750, 750);
        glutCreateWindow("Polygon Filling");
    }

    float x1, y1, x2, y2, x, y, step, dx, dy, xinc, yinc;

    void Line(int x1, int y1, int x2, int y2);
    void boundaryFour(int x, int y, int fc, int bc);
    void boundaryEight(int x, int y, int fc, int bc);
    void floodFour(int x, int y, int fillcolor, int interiorcolor);
    void floodEight(int x, int y, int fillcolor, int interiorcolor);
};

// Function to draw a line using DDA algorithm
void poly::Line(int x1, int y1, int x2, int y2) {
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    xinc = dx / step;
    yinc = dy / step;
    x = x1;
    y = y1;

    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();

    for (int k = 1; k < step; ++k) {
        x += xinc;
        y += yinc;
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
    }
}

// Boundary fill algorithm (4-connected)
void poly::boundaryFour(int x, int y, int fc, int bc) {
    GLubyte pixel[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
    int color = (pixel[0] << 16) | (pixel[1] << 8) | pixel[2];

    if (color != bc && color != fc) {
        glColor3f(fc / 255.0f, fc / 255.0f, fc / 255.0f); // Set fill color
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();

        // Recurse in four directions
        boundaryFour(x, y - 1, fc, bc);
        boundaryFour(x, y + 1, fc, bc);
        boundaryFour(x - 1, y, fc, bc);
        boundaryFour(x + 1, y, fc, bc);
    }
}

// Boundary fill algorithm (8-connected)
void poly::boundaryEight(int x, int y, int fc, int bc) {
    GLubyte pixel[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
    int color = (pixel[0] << 16) | (pixel[1] << 8) | pixel[2];

    if (color != bc && color != fc) {
        glColor3f(fc / 255.0f, fc / 255.0f, fc / 255.0f); // Set fill color
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();

        // Recurse in eight directions
        boundaryEight(x, y - 1, fc, bc);
        boundaryEight(x, y + 1, fc, bc);
        boundaryEight(x - 1, y, fc, bc);
        boundaryEight(x + 1, y, fc, bc);
        boundaryEight(x + 1, y - 1, fc, bc);
        boundaryEight(x + 1, y + 1, fc, bc);
        boundaryEight(x - 1, y - 1, fc, bc);
        boundaryEight(x - 1, y + 1, fc, bc);
    }
}

// Flood fill algorithm (4-connected)
void poly::floodFour(int x, int y, int fillcolor, int interiorcolor) {
    GLubyte pixel[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
    int color = (pixel[0] << 16) | (pixel[1] << 8) | pixel[2];

    if (color == interiorcolor) {
        glColor3f(fillcolor / 255.0f, fillcolor / 255.0f, fillcolor / 255.0f); // Set fill color
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();

        // Recurse in four directions
        floodFour(x, y - 1, fillcolor, interiorcolor);
        floodFour(x, y + 1, fillcolor, interiorcolor);
        floodFour(x - 1, y, fillcolor, interiorcolor);
        floodFour(x + 1, y, fillcolor, interiorcolor);
    }
}

// Flood fill algorithm (8-connected)
void poly::floodEight(int x, int y, int fillcolor, int interiorcolor) {
    GLubyte pixel[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
    int color = (pixel[0] << 16) | (pixel[1] << 8) | pixel[2];

    if (color == interiorcolor) {
        glColor3f(fillcolor / 255.0f, fillcolor / 255.0f, fillcolor / 255.0f); // Set fill color
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();

        // Recurse in eight directions
        floodEight(x, y - 1, fillcolor, interiorcolor);
        floodEight(x, y + 1, fillcolor, interiorcolor);
        floodEight(x - 1, y, fillcolor, interiorcolor);
        floodEight(x + 1, y, fillcolor, interiorcolor);
        floodEight(x + 1, y - 1, fillcolor, interiorcolor);
        floodEight(x + 1, y + 1, fillcolor, interiorcolor);
        floodEight(x - 1, y - 1, fillcolor, interiorcolor);
        floodEight(x - 1, y + 1, fillcolor, interiorcolor);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    poly d;

    // Example case for polygon creation and filling
    d.Line(300, 100, 400, 100);
    d.Line(300, 100, 300, 200);
    d.Line(300, 200, 200, 200);
    d.Line(200, 200, 200, 300);
    d.Line(200, 300, 300, 300);
    d.Line(300, 300, 300, 400);
    d.Line(300, 400, 400, 400);
    d.Line(400, 400, 400, 300);
    d.Line(400, 300, 500, 300);
    d.Line(500, 300, 500, 200);
    d.Line(500, 200, 400, 200);
    d.Line(400, 100, 400, 200);
    d.Line(300, 200, 400, 200);
    d.Line(400, 200, 400, 300);
    d.Line(400, 300, 300, 300);
    d.Line(300, 300, 300, 200);

    // Example of flood fill or boundary fill after drawing the polygon
    d.floodFour(350, 250, 255, 255); // Fill the inside with color (255,255,255)
    // d.boundaryFour(350, 250, 0, 255); // Optional: Use boundary fill instead.

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutDisplayFunc(display);

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 750.0, 0.0, 750.0);

    glutMainLoop();
    return 0;
}