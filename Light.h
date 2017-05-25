#ifndef LIGHT
#define LIGHT

#include <GL\glew.h>
#include <glm\glm.hpp>

class Light{

	friend class Renderer;

public:

	GLfloat strength = 1.0f;
	GLfloat deltaStrength = 0.05f;

	Light(GLuint shaderProgram, glm::vec3 pos, glm::vec3 color);
	
	void setPosition(glm::vec3 position);

	void setStrength(GLfloat str) { this->strength = str; }

	void incStrength() { this->strength += deltaStrength; }

	void decrStrength() { this->strength -= deltaStrength; }

private:
	GLuint lightColorLoc;
	GLuint lightPosLoc;

	glm::vec3 position;
	glm::vec3 color;


};

#endif