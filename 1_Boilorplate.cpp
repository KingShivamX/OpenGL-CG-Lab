#include <GL/glut.h>

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glOrtho(0, 100, 0, 100, 0, 100);
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex2i(50, 70);
	glColor3f(0, 1, 0);
	glVertex2i(25, 25);
	glColor3f(0, 0, 1);
	glVertex2i(75, 25);
	glEnd();

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 100);
	glutCreateWindow("opengl");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}