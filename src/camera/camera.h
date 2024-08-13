// camera.h
#ifndef CAMERA_H
#define CAMERA_H

#include "..\state.h"

typedef struct Camera {
    vec3 position;
    vec3 front;
    vec3 up;
    mat4 view;
    mat4 projection;
    mat4 viewProjection;
    float yaw;
    float pitch;
    float speed;
    float sensitivity;
} Camera;

void initCamera(Camera *camera, float width, float height);
void updateCamera(Camera *camera);
void applyCamera(const Camera *camera, GLuint shaderProgram);

#endif
