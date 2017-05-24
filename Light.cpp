
#include "Light.h"

Light::Light(GLuint shaderProgram, glm::vec3 pos, glm::vec3 color){
	lightPosLoc = glGetUniformLocation(shaderProgram, "lightPos");
	lightColorLoc = glGetUniformLocation(shaderProgram, "lightColor");

	this->color = color;
	this->position = pos;
}


void Light::setPosition(glm::vec3 pos){
	position = pos;
}