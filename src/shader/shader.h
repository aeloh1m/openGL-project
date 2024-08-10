#ifndef SHADER_H
#define SHADER_H

#include "..\state.h" // Ensure this includes GLAD and GLFW headers

GLuint createShaderProgram(const char *vertexPath, const char *fragmentPath);

#endif // SHADER_H