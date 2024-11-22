#include <GL/glut.h>
using namespace std;

// Function to initialize the OpenGL projection
void init()
{
    glMatrixMode(GL_PROJECTION); // Set projection matrix mode
    glLoadIdentity();            // Load identity matrix (reset any previous transformations)
    glOrtho(0, 640, 0, 480, -1, 1); // Define orthographic projection (coordinates from 0 to 640 for x, and 0 to 480 for y)
}

// Function to implement the boundary fill algorithm
void boundaryFill(float x, float y, float* fillColor, float* borderColor)
{
    float currentColor[3];
    // Read the color of the current pixel at (x, y)
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, currentColor);
    
    // Check if the current pixel is not of the border color or the fill color
    if ((currentColor[0] != borderColor[0] || currentColor[1] != borderColor[1] ||
         currentColor[2] != borderColor[2]) &&
        (currentColor[0] != fillColor[0] || currentColor[1] != fillColor[1] ||
         currentColor[2] != fillColor[2]))
    {
        // Set the fill color for the pixel
        glColor3f(fillColor[0], fillColor[1], fillColor[2]);
        glBegin(GL_POINTS); // Start drawing points
        glVertex2i(x, y);  // Plot the pixel at (x, y)
        glEnd();
        glFlush(); // Force the drawing to happen immediately
        
        // Recursively call the boundaryFill function to fill adjacent pixels
        boundaryFill(x + 2, y, fillColor, borderColor); // Right
        boundaryFill(x - 2, y, fillColor, borderColor); // Left
        boundaryFill(x, y + 2, fillColor, borderColor); // Up
        boundaryFill(x, y - 2, fillColor, borderColor); // Down
    }
}

// Display function to draw the shape and start the filling process
void display()
{
    glLineWidth(3);  // Set line width for the border
    glPointSize(2);  // Set point size for the fill
    
    // Define the border color as red and fill color as green
    float border[] = {1.0f, 0.0f, 0.0f}; // red
    float fill[] = {0.0f, 1.0f, 0.0f};   // green

    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    // Set the current drawing color to the border color (red)
    glColor3f(border[0], border[1], border[2]);

    // Draw a rectangle using the border color
    glBegin(GL_LINE_LOOP);
    glVertex2i(150, 150); // Bottom-left corner
    glVertex2i(450, 150); // Bottom-right corner
    glVertex2i(450, 450); // Top-right corner
    glVertex2i(150, 450); // Top-left corner
    glEnd();
    
    glFlush(); // Ensure that drawing happens immediately

    // Call boundaryFill to fill the shape with the specified fill color inside the boundary
    boundaryFill(300, 300, fill, border); // Start the fill process at the center of the rectangle
}

// Main function to initialize GLUT and start the rendering loop
int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Use single buffering and RGB color mode
    glutInitWindowSize(640, 480); // Set the window size
    glutInitWindowPosition(200, 200); // Set the window position
    glutCreateWindow("Boundary Fill Algorithm"); // Create the window with the specified title

    glutDisplayFunc(display); // Set the display function to be called when rendering
    init(); // Call the initialization function

    glutMainLoop(); // Enter the GLUT main event loop (keeps the program running)
    
    return 0;
}

//2

#include<GL/glut.h>

void init()
{
    glMatrixMode(GL_PROJECTION);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 500, 0, 500);
}

void circle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    while (x <= y)
    {
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        x++;
    }
    glEnd();
    glFlush();
}

void fill(int x, int y, float fc[], float bc[])
{
    float font[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, font);
    if ((fc[0] != font[0] || fc[1] != font[1] || fc[2] != font[2]) && (bc[0] != font[0] || bc[1] != font[1] || bc[2] != font[2]))
    {
        glBegin(GL_POINTS);
        glColor3fv(fc);
        glVertex2i(x, y);
        glEnd();
        glFlush();

        fill(x + 1, y, fc, bc);
        fill(x - 1, y, fc, bc);
        fill(x, y + 1, fc, bc);
        fill(x, y - 1, fc, bc);
    }

}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    float fc[] = { 1.0,1.0,0.0 };
    float bc[] = { 1.0,0.0,0.0 };

    circle(250, 250, 50);

    fill(250, 250, fc, bc);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("FLOOD FILL");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}