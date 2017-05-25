#ifndef ANIMATIONFRAME
#define ANIMATIONFRAME

#include <glm\glm.hpp>
#include <GL/glew.h>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>


struct AnimationFrame {

	GLfloat time;
	glm::quat rotation;

	AnimationFrame(GLfloat time, glm::quat position) : time(time), rotation(position) {}
	AnimationFrame() {}

};

#endif