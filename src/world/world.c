#include "world.h" // Your world header
// Include necessary headers
#include "..\state.h"

// Vertex data for a ground plane
GLfloat vertices[] = {
    -0.5f, 0.0f, -0.5f, // Bottom left
    0.5f, 0.0f, -0.5f,  // Bottom right
    0.5f, 0.0f, 0.5f,   // Top right
    -0.5f, 0.0f, 0.5f   // Top left
};

GLuint indices[] = {
    0, 1, 2, 2, 3, 0 // Two triangles forming a square
};

GLuint VBO, VAO;

void initBuffers() {
    float vertices[] = {
        // Positions
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void drawGround(GLuint shaderProgram) {
    glUseProgram(shaderProgram);

    // Example of drawing a rectangle (assuming VAO and VBO are correctly initialized)
    glBindVertexArray(VAO); // Make sure VAO is correctly bound
    glDrawArrays(GL_TRIANGLES, 0, 6); // Adjust this if using GL_TRIANGLES or GL_QUADS
    glBindVertexArray(0);
}
void drawTriangle(GLuint shaderProgram) {
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}