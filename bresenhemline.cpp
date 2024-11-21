#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

void init() {
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 500, 0, 500, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT);

	//GLfloat x1 = 120, y1 = 50, x2 = 300, y2 = 400, M, dx, dy, p, x, y;
	GLfloat x1 = 250, y1 = 250, x2 = 50, y2 = 10, M, dx, dy, p, x, y;

	if ((x2 - x1) == 0) M = (y2 - y1); // Vertical line
	else M = (y2 - y1) / (x2 - x1);

	dx = fabs(x2 - x1);
	dy = fabs(y2 - y1);

	if (fabs(M) < 1) { // slope less them 1.

		if (x1 > x2) {
			swap(x1, x2);
			swap(y1, y2);
		}

		p = (2 * dy) - dx; // decision parameter

		x = x1; // initial
		y = y1;

		glBegin(GL_POINTS);
		while (x <= x2) {
			glVertex2f(x, y);
			x += 1; // increment everytime

			if (p >= 0) {
				y += ((y2 > y1) ? 1 : -1); // Adjust for line direction
				p = p + (2 * dy) - (2 * dx);
			}
			else {
				y = y; // same remain
				p = p + (2 * dy);
			}
		}
		glEnd();

	}
	else {


		if (y1 > y2) {
			swap(x1, x2);
			swap(y1, y2);
		}

		p = (2 * dx) - dy; // decision parameter

		x = x1; // initial
		y = y1;

		glBegin(GL_POINTS);
		while (y <= y2) {
			glVertex2f(x, y);
			y += 1; // increment everytime

			if (p >= 0) {
				x += (x2 > x1 ? 1 : -1); // Adjust for line directio
				p = p + (2 * dx) - (2 * dy);
			}
			else {
				x = x; // same remain
				p = p + (2 * dx);
			}
		}
		glEnd();

	}


	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(400, 200);
	glutInitWindowSize(500, 500);
	glutCreateWindow("opengl");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();

	return 0;
}
