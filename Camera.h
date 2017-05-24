#ifndef CAMERA
#define CAMERA

#include <glm/detail/type_mat4x4.hpp>
#include <glm/vec3.hpp>

class Camera {
public:
	glm::mat4 mProjection;
	glm::mat4 mView;
	glm::vec3 mPostion;

	glm::vec3 mTarget;

	float hAngle;
	float vAngle;
	float distance;

	Camera(glm::vec3 target);
	void setPosition();
	void updateView(glm::vec3 pos, glm::vec3 posAndFront, glm::vec3 up);
	void changeTarget(glm::vec3 target);

	float getHAngle() {
		return hAngle;
	}
	float getVAngle(){
		return vAngle;
	}
	float getDistance(){
		return distance;
	}

	void setHAngle(float angle){
		hAngle = angle;
		setPosition();
	}
	void setVAngle(float angle){
		vAngle = angle;
		setPosition();
	}
	void setDistance(float dist){
		distance = dist;
		setPosition();
	}
};


#endif 