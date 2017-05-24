#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>
#include "Camera.h"

Camera::Camera(glm::vec3 target) : mTarget(target) {
	
	hAngle = glm::half_pi<float>()/2;
	vAngle = glm::half_pi<float>();
	distance = 5.0f;
	
	mTarget = target;

	setPosition();

	//mView = glm::lookAt(position, target, glm::vec3(0.0f, 1.0f, 0.0f));

	mProjection = glm::perspective(glm::radians(45.0f), (float)4 / (float)3, 0.1f, 100.0f);

}

void Camera::setPosition() {
	//mView = glm::lookAt(position, mTarget, glm::vec3(0.0f, 1.0f, 0.0f));

	mPostion.x = (float)(distance * cos(hAngle));
	mPostion.y = (float)(distance * sin(vAngle));
	mPostion.z = (float)(distance * sin(hAngle));

	mView = glm::lookAt(
		mPostion,
		mTarget,
		glm::vec3(0, 1, 0)
		);
		
}

void Camera::updateView(glm::vec3 pos, glm::vec3 front, glm::vec3 up){
	mView = glm::lookAt(pos, pos + front, up);
}

void Camera::changeTarget(glm::vec3 target){
	mTarget = target;
	mView = glm::lookAt(mPostion, mTarget, glm::vec3(0.0f, 1.0f, 0.0f));
}

