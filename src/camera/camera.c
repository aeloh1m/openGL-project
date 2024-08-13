#include "camera.h"

void initCamera(Camera *camera, float width, float height)
{
    glm_vec3_copy((vec3){0.0f, 0.0f, 3.0f}, camera->position); // Camera at (0, 0, 3)
    glm_vec3_copy((vec3){0.0f, 0.0f, -1.0f}, camera->front);   // Looking towards negative z-axis
    glm_vec3_copy((vec3){0.0f, 1.0f, 0.0f}, camera->up);       // Up vector is (0, 1, 0)

    camera->yaw = -90.0f;   // Start by looking straight ahead
    camera->pitch = 0.0f;
    camera->speed = 2.5f;
    camera->sensitivity = 0.1f;

    // Initialize projection matrix with the given width and height
    glm_perspective(glm_rad(45.0f), width / height, 0.1f, 100.0f, camera->projection);

    // Initialize view matrix
    glm_look(camera->position, camera->front, camera->up, camera->view);

    // Combine projection and view matrices
    glm_mat4_mul(camera->projection, camera->view, camera->viewProjection);
}

void updateCamera(Camera *camera) {
    // Calculate the view matrix based on the current camera position and direction
    vec3 center;
    glm_vec3_add(camera->position, camera->front, center);
    glm_lookat(camera->position, center, camera->up, camera->view);

    // Update the view-projection matrix
    glm_mat4_mul(camera->projection, camera->view, camera->viewProjection);
}

void applyCamera(const Camera *camera, GLuint shaderProgram)
{
    glUseProgram(shaderProgram);

    // Set the view-projection matrix uniform in the shader
    GLint viewProjectionLoc = glGetUniformLocation(shaderProgram, "u_ViewProjection");
    glUniformMatrix4fv(viewProjectionLoc, 1, GL_FALSE, (const GLfloat *)camera->viewProjection);
}
