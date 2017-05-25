#ifndef CHILDMODEL
#define CHILDMODEL

#include "Model.h"

class ChildModel : public Model {

public:
	
	ChildModel(std::shared_ptr<Mesh> mesh, std::shared_ptr<Model> parent);

	//virtual void setPosition(glm::vec3 position);

	//virtual void setRotation(glm::vec3 rotationAxis, GLfloat angle);

	void recalculateTransform();

	//virtual void setTexture(GLuint texture);

private:
	
	std::shared_ptr<Model> parent;

};

#endif