#include <GL/glut.h>
#include <cmath>

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glOrtho(0, 100, 0, 100, 0, 100);
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10);
	glBegin(GL_POINTS);
		glColor3f(1, 0, 0);
		glVertex2i(50, 50);
		//glVertex2i(10,10);
		//glVertex2i(15, 15);
	glEnd();

	glLineWidth(5);
	glBegin(GL_LINES);
		glColor3f(1, 1, 0);
		glVertex2i(5, 5);
		glVertex2i(50, 5);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0, 1, 1);
		glVertex2f(60, 50);
		glVertex2f(90, 50);
		glVertex2f(90, 5);
		glVertex2f(60, 5);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 0);
		glVertex2i(5, 10);
		glColor3f(0, 1, 0);
		glVertex2i(40, 10);
		glColor3f(0, 0, 1);
		glVertex2f(22.5, 45);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1, 0, 1);
		glVertex2f(15, 55);
		glVertex2f(30, 55);
		glVertex2f(40, 75);
		glVertex2f(23, 90);
		glVertex2f(5, 75);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 1, 1);
	for (int i = 0; i < 100; i++) {
		float angle = 2.0f * 3.14159f * i / 100;
		glVertex2f(75 + cos(angle) * 20, 75 + sin(angle) * 20);
	}
	glEnd();

	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(300, 100);
	glutCreateWindow("opengl");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}