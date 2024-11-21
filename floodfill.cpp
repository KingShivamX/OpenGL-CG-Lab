#include <GL/glut.h>

void initOpenGL() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Set up orthographic projection
}

void setPixelColor(float* color) {
    glColor3f(color[0], color[1], color[2]);
}

void drawRectangle() {
    glColor3f(0, 1, 1); // Cyan color
    glBegin(GL_LINE_LOOP);
    glVertex2i(200, 200);
    glVertex2i(400, 200);
    glVertex2i(400, 400);
    glVertex2i(200, 400);
    glEnd();
    glFlush();
}

void readPixelColor(int x, int y, float* color) {
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

bool isMatchingColor(float* color1, float* color2) {
    return color1[0] == color2[0] && color1[1] == color2[1] && color1[2] == color2[2];
}

void floodFill(int x, int y, float* oldColor, float* newColor) {
    float color[3];
    readPixelColor(x, y, color);

    if (isMatchingColor(color, oldColor) && !isMatchingColor(color, newColor)) {
        setPixelColor(newColor);

        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();

        if (x < 640 && x > 0 && y < 480 && y > 0) {
            floodFill(x + 1, y, oldColor, newColor); // Right
            floodFill(x - 1, y, oldColor, newColor); // Left
            floodFill(x, y + 1, oldColor, newColor); // Up
            floodFill(x, y - 1, oldColor, newColor); // Down
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawRectangle();

    float oldColor[] = { 0, 0, 0 }; // Black (background)
    float newColor[] = { 0, 1, 1 }; // Cyan (fill color)
    floodFill(300, 300, oldColor, newColor);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Flood Fill Algorithm");

    initOpenGL();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

// 2

#include <GL/glut.h>
#include <cmath>
#include <iostream>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);       // Coordinate system
}

// Function for boundary fill
void floodfill(int x, int y, float* fillColor, float* boundaryColor) {
    float font[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, font);
    if ((font[0] != fillColor[0] || font[1] != fillColor[1] || font[2] != fillColor[2]) && (font[0] == boundaryColor[0] && font[1] == boundaryColor[1] && font[1] == boundaryColor[1]))
    {
        glBegin(GL_POINTS);
        glColor3fv(fillColor);
        glVertex2i(x, y);
        glEnd();
        glFlush();

        floodfill(x + 1, y, fillColor, boundaryColor);
        floodfill(x - 1, y, fillColor, boundaryColor);
        floodfill(x, y + 1, fillColor, boundaryColor);
        floodfill(x, y - 1, fillColor, boundaryColor);
    }
}

// Function to draw a circle using the midpoint algorithm
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 1 - r;

    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 1.0); // Blue boundary color
    while (x <= y) {
        // Draw all eight octants
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

        if (d < 0) {
            d = d + 2 * x + 1;
        }
        else {
            d = d + 2 * (x - y) + 1;
            y--;
        }
        x++;
    }
    glEnd();
    glFlush();
}

void fillCircle() {
    glClear(GL_COLOR_BUFFER_BIT);
    float fc[] = { 1.0,0.0,0.0 };
    float bc[] = { 1.0,1.0,1.0 };

    drawCircle(250, 250, 50);
    floodfill(250, 250, fc, bc);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Boundary Fill - Circle");
    init();
    glutDisplayFunc(fillCircle);
    glutMainLoop();
    return 0;
}
