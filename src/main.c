#include "state.h"

// Function prototypes
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window, Camera *camera);

int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL Project", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Load GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fprintf(stderr, "Failed to initialize GLAD\n");
        return -1;
    }

    // Initialize GL settings
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    Camera camera;
    initCamera(&camera, 800.0f, 600.0f);

    // Set up shaders
    GLuint shaderProgram = createShaderProgram("../vertex_shader.glsl", "../fragment_shader.glsl");
    if (shaderProgram == 0)
    {
        fprintf(stderr, "Failed to create shader program\n");
        return -1;
    }

    // Initialize buffers
    initBuffers();

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Update camera based on input
        processInput(window, &camera);

        // Update the camera matrix
        updateCamera(&camera); // No need for width and height
        applyCamera(&camera, shaderProgram);

        // Render
        glClear(GL_COLOR_BUFFER_BIT);
        drawGround(shaderProgram); // or drawTriangle(shaderProgram);

        // Swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glfwTerminate();
    return 0;
}

// Process input function
void processInput(GLFWwindow *window, Camera *camera)
{
    vec3 direction;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        glm_vec3_scale(camera->front, camera->speed, direction); // Move forward
        glm_vec3_add(camera->position, direction, camera->position);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        glm_vec3_scale(camera->front, camera->speed, direction); // Move backward
        glm_vec3_sub(camera->position, direction, camera->position);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        glm_vec3_cross(camera->front, camera->up, direction); // Calculate the right vector
        glm_normalize(direction);
        glm_vec3_scale(direction, camera->speed, direction); // Move left
        glm_vec3_sub(camera->position, direction, camera->position);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        glm_vec3_cross(camera->front, camera->up, direction); // Calculate the right vector
        glm_normalize(direction);
        glm_vec3_scale(direction, camera->speed, direction); // Move right
        glm_vec3_add(camera->position, direction, camera->position);
    }
}

// Resize callback function
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}
