#include <GL/glut.h>

void init() {
    glClearColor(0.2, 0.2, 0.2, 1); // Darker background for contrast
    gluOrtho2D(-250, 250, -150, 150);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Borders
    glBegin(GL_LINES);
    glColor3f(0.6, 0.6, 1); // Light blue borders

    glVertex2i(-250, -50);
    glVertex2i(250, -50);

    glVertex2i(-250, 50);
    glVertex2i(250, 50);

    glVertex2i(-150, -150);
    glVertex2i(-150, 150);

    glVertex2i(-50, -150);
    glVertex2i(-50, 150);

    glVertex2i(50, -150);
    glVertex2i(50, 150);

    glVertex2i(150, -150);
    glVertex2i(150, 150);
    glEnd();

    // Border points
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.5, 0.0); // Orange points
    glVertex2i(150, 50);
    glVertex2i(150, -50);
    glVertex2i(50, 50);
    glVertex2i(50, -50);
    glVertex2i(-50, 50);
    glVertex2i(-50, -50);
    glVertex2i(-150, 50);
    glVertex2i(-150, -50);
    glEnd();

    // 1 - A
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0); // Red for 'A'

    glVertex2i(-200, 120);
    glVertex2i(-229, 70);

    glVertex2i(-200, 120);
    glVertex2i(-171, 70);

    glVertex2i(-214, 95);
    glVertex2i(-186, 95);
    glEnd();

    // 2 - E
    glBegin(GL_LINES);
    glColor3f(0, 1, 0); // Green for 'E'
    glVertex2i(-120, 120);
    glVertex2i(-80, 120);

    glVertex2i(-120, 100);
    glVertex2i(-90, 100);

    glVertex2i(-120, 80);
    glVertex2i(-80, 80);

    glVertex2i(-120, 120);
    glVertex2i(-120, 80);
    glEnd();

    // 3 - F
    glBegin(GL_LINES);
    glColor3f(0, 0, 1); // Blue for 'F'
    glVertex2i(-20, 120);
    glVertex2i(20, 120);

    glVertex2i(-20, 100);
    glVertex2i(10, 100);

    glVertex2i(-20, 120);
    glVertex2i(-20, 80);
    glEnd();

    // 4 - H
    glBegin(GL_LINES);
    glColor3f(1, 0, 1); // Magenta for 'H'
    glVertex2i(80, 100);
    glVertex2i(110, 100);

    glVertex2i(80, 120);
    glVertex2i(80, 80);

    glVertex2i(110, 80);
    glVertex2i(110, 120);
    glEnd();

    // 5 - I
    glBegin(GL_LINES);
    glColor3f(1, 1, 0); // Yellow for 'I'
    glVertex2i(200, 120);
    glVertex2i(200, 80);

    glVertex2i(180, 120);
    glVertex2i(220, 120);

    glVertex2i(220, 80);
    glVertex2i(180, 80);
    glEnd();

    // 6 - K
    glBegin(GL_LINES);
    glColor3f(0.5, 0, 1); // Purple for 'K'
    glVertex2i(-220, -30);
    glVertex2i(-220, 30);

    glVertex2i(-180, 30);
    glVertex2i(-220, 0);

    glVertex2i(-180, -30);
    glVertex2i(-220, 0);
    glEnd();

    // 7 - L
    glBegin(GL_LINES);
    glColor3f(0, 1, 1); // Cyan for 'L'
    glVertex2i(-120, -20);
    glVertex2i(-80, -20);

    glVertex2i(-120, 20);
    glVertex2i(-120, -20);
    glEnd();

    // 8 - M
    glBegin(GL_LINES);
    glColor3f(1, 0.5, 0); // Orange for 'M'
    glVertex2i(-20, 20);
    glVertex2i(-20, -20);

    glVertex2i(10, -20);
    glVertex2i(10, 20);

    glVertex2i(10, 20);
    glVertex2i(-5, 0);

    glVertex2i(-20, 20);
    glVertex2i(-5, 0);
    glEnd();

    // 9 - N
    glBegin(GL_LINES);
    glColor3f(0.5, 1, 0); // Light green for 'N'
    glVertex2i(80, 20);
    glVertex2i(80, -20);

    glVertex2i(110, -20);
    glVertex2i(110, 20);

    glVertex2i(80, 20);
    glVertex2i(110, -20);
    glEnd();

    // 10 - T
    glBegin(GL_LINES);
    glColor3f(0, 0.5, 1); // Sky blue for 'T'
    glVertex2i(200, 20);
    glVertex2i(200, -20);

    glVertex2i(180, 20);
    glVertex2i(220, 20);
    glEnd();

    // 11 - V
    glBegin(GL_LINES);
    glColor3f(1, 0, 0.5); // Pink for 'V'
    glVertex2i(-200, -130);
    glVertex2i(-229, -80);

    glVertex2i(-200, -130);
    glVertex2i(-171, -80);
    glEnd();

    // 12 - W
    glBegin(GL_LINES);
    glColor3f(0.5, 1, 1); // Light cyan for 'W'
    glVertex2i(-140, -80);
    glVertex2i(-120, -120);

    glVertex2i(-80, -120);
    glVertex2i(-60, -80);

    glVertex2i(-120, -120);
    glVertex2i(-100, -100);

    glVertex2i(-80, -120);
    glVertex2i(-100, -100);
    glEnd();

    // 13 - X
    glBegin(GL_LINES);
    glColor3f(1, 1, 0.5); // Light yellow for 'X'
    glVertex2i(10, -80);
    glVertex2i(-20, -120);

    glVertex2i(-20, -80);
    glVertex2i(10, -120);
    glEnd();

    // 14 - Y
    glBegin(GL_LINES);
    glColor3f(0.5, 0, 0.5); // Deep purple for 'Y'
    glVertex2i(110, -80);
    glVertex2i(95, -100);

    glVertex2i(80, -80);
    glVertex2i(95, -100);

    glVertex2i(95, -100);
    glVertex2i(95, -120);
    glEnd();

    // 15 - Z
    glBegin(GL_LINES);
    glColor3f(1, 0.8, 0); // Gold for 'Z'
    glVertex2i(180, -80);
    glVertex2i(220, -80);

    glVertex2i(180, -120);
    glVertex2i(220, -120);

    glVertex2i(220, -80);
    glVertex2i(180, -120);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Alphabets Display");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
