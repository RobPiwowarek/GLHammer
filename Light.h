#ifndef LIGHT
#define LIGHT

#include <GL\glew.h>
#include <glm\glm.hpp>

class Light{

	friend class Renderer;

public:

	GLfloat strength;

	Light(GLuint shaderProgram, glm::vec3 pos, glm::vec3 color);
	
	void setPosition(glm::vec3 position);

private:
	GLuint lightColorLoc;
	GLuint lightPosLoc;

	glm::vec3 position;
	glm::vec3 color;


};

#endif