#include <GL/glut.h>
#include <iostream>
#include <vector>
using namespace std;


void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 500, 0, 500, 0, 1);
	glMatrixMode(GL_PROJECTION);
}

vector<int> LE(500, 500), RE(500, 0); // left edge to right edge.

void intersection(GLint x1, GLint y1, GLint x2, GLint y2){
	if (y1 > y2) {
		swap(x1, x2);
		swap(y1, y2);
	}

	GLfloat M;
	if((x2-x1) == 0) M = (y2 - y1);
	else M = (y2 - y1) / (x2 - x1);

	GLint x = x1;
	for (int y = y1; y <= y2; y++) {
		if (x < LE[y]) LE[y] = x;
		if (x > RE[y]) RE[y] = x;
		x = x + M;
	}
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT);

	// now to draw polygon
	GLint p1[2] = { 125, 250 };
	GLint p2[2] = { 250, 125 };
	GLint p3[2] = { 375, 250 };
	GLint p4[2] = { 250, 375 };

	glBegin(GL_LINE_LOOP);
		glVertex2iv(p1);
		glVertex2iv(p2);
		glVertex2iv(p3);
		glVertex2iv(p4);  
	glEnd();

	intersection(p1[0], p1[1], p2[0], p2[1]);
	intersection(p2[0], p2[1], p3[0], p3[1]);
	intersection(p3[0], p3[1], p4[0], p4[1]);
	intersection(p4[0], p4[1], p1[0], p1[1]);

	
	for (int y = 0; y < 500; y++) {
		for (int x = LE[y]; x < RE[y]; x++) {
			glBegin(GL_POINTS);
				glVertex2f(x, y);
			glEnd();
			glFlush();
		}
	}

	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(300, 200);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Scanline");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}


// 2



#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intersections[500];  // Store all intersection points for each scan line

// Initialize OpenGL
void init() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void Intersection(GLint x1, GLint y1, GLint x2, GLint y2) {
    if (y1 > y2) {
        swap(x1, x2);
        swap(y1, y2);
    }

    // Calculate slope (m)
    float m = (y2 != y1) ? (float)(x2 - x1) / (y2 - y1) : 0;
    float x = x1;

    // Store intersection points for each scan line
    for (int y = y1; y <= y2; y++) {
        intersections[y].push_back((int)round(x));
        x += m;
    }
}

void Scan_Fill() {
    GLint P1[2] = { 100, 100 };  // Vertex 1
    GLint P2[2] = { 100, 400 };  // Vertex 2
    GLint P3[2] = { 200, 300 };  // Vertex 3 (concave part)
    GLint P4[2] = { 300, 400 };  // Vertex 4
    GLint P5[2] = { 300, 100 };  // Vertex 5


    for (int i = 0; i < 500; i++) {
        intersections[i].clear();
    }

    glBegin(GL_LINE_LOOP);
    glVertex2iv(P1);
    glVertex2iv(P2);
    glVertex2iv(P3);
    glVertex2iv(P4);
    glVertex2iv(P5);
    glEnd();

    Intersection(P1[0], P1[1], P2[0], P2[1]);
    Intersection(P2[0], P2[1], P3[0], P3[1]);
    Intersection(P3[0], P3[1], P4[0], P4[1]);
    Intersection(P4[0], P4[1], P5[0], P5[1]);
    Intersection(P5[0], P5[1], P1[0], P1[1]);

    for (int y = 0; y < 500; y++) {
        if (!intersections[y].empty()) {
            sort(intersections[y].begin(), intersections[y].end());  // Sort intersection points
            for (size_t i = 0; i < intersections[y].size(); i += 2) {
                if (i + 1 < intersections[y].size()) {
                    // Fill between pairs of points
                    for (int x = intersections[y][i]; x <= intersections[y][i + 1]; x++) {
                        glColor3f(1.0, 0.0, 0.0);  // Set the fill color (red)
                        glBegin(GL_POINTS);
                        glVertex2i(x, y);
                        glEnd();
                        glFlush();
                    }
                }
            }
        }
    }
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Concave Polygon Scan-Line Fill (Corrected)");
    init();
    glutDisplayFunc(Scan_Fill);
    glutMainLoop();
    return 0;
}