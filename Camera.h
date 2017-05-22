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

	Camera(glm::vec3 position, glm::vec3 target);
	void setPosition(glm::vec3 position);
};


#endif 