#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>
#include "Camera.h"

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);

glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

Camera::Camera(glm::vec3 position, glm::vec3 target) : mTarget(target) {
	mView = glm::lookAt(position, target, cameraUp);
	mProjection = glm::perspective(glm::radians(45.0f), (float)4 / (float)3, 0.1f, 100.0f);
}

void Camera::setPosition(glm::vec3 position) {
	mView = glm::lookAt(position, mTarget, glm::vec3(0.0f, 1.0f, 0.0f));
}

