#include "world.h" // Your world header
#include "..\state.h"

void drawGround(float size, int divisions)
{
    float halfSize = size / 2.0f;
    float step = size / divisions;

    glBegin(GL_QUADS);
    for (int i = 0; i < divisions; ++i)
    {
        for (int j = 0; j < divisions; ++j)
        {
            float x = -halfSize + i * step;
            float z = -halfSize + j * step;

            glColor3f(0.3f, 0.8f, 0.3f); // Green color for the ground

            glVertex3f(x, 0.0f, z);               // Bottom left
            glVertex3f(x + step, 0.0f, z);        // Bottom right
            glVertex3f(x + step, 0.0f, z + step); // Top right
            glVertex3f(x, 0.0f, z + step);        // Top left
        }
    }
    glEnd();
}

// Display a Triangle ah
void displayTriangle()
{

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    // First vertex (Red)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.9f, -0.9f);

    // Second vertex (Green)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.0f, 0.9f);

    // Third vertex (Blue)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.9f, -0.0f);

    glEnd();
    /* Swap front and back buffers */

}
