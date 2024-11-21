#include <GL/glut.h>

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(-240, 240, -240, 240);
}

void art() {
	glClear(GL_COLOR_BUFFER_BIT);


	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.5, 0.2);
	glVertex2f(0.0, 160);
	glVertex2f(-60, 80);
	glVertex2f(60, 80);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.5, 0.2);
	glVertex2f(60, 80);
	glVertex2f(180, 80);
	glVertex2f(120, 0.0);
	glEnd();


	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.5, 0.2);
	glVertex2f(120, 0.0);
	glVertex2f(180, -80);
	glVertex2f(60, -80);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.5, 0.2);
	glVertex2f(60, -80);
	glVertex2f(0.0, -160);
	glVertex2f(-60, -80);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.5, 0.2);
	glVertex2f(-60, -80);
	glVertex2f(-180, -80);
	glVertex2f(-120, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.5, 0.2);
	glVertex2f(-120, 0.0);
	glVertex2f(-180, 80);
	glVertex2f(-60, 80);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.3, 0.0);
	glVertex2f(60, 80);
	glVertex2f(120, 0.0);
	glVertex2f(60, -80);
	glVertex2f(-60, -80);
	glVertex2f(-120, 0.0);
	glVertex2f(-60, 80);
	glEnd();



	glFlush();
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Jiyas Window");
	init();
	glutDisplayFunc(art);
	glutMainLoop();

	return 0;
}