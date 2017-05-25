#ifndef MODEL
#define MODEL

#include "Mesh.h"
#include "Texture.h"

#include <list>

#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

#include <glm\gtc\type_ptr.hpp>
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

class Model {
public:
    void setTransform(glm::mat4 transform);

    Model(std::shared_ptr<Mesh> mesh);

    void setPosition(glm::vec3 position);

    void setRotation(glm::vec3 rotationAxis, GLfloat angle);

	void setRotation(glm::quat rotationQuat);

	void joinRotation(glm::vec3 rotationAxis, GLfloat angle);

    virtual void recalculateTransform();

	void setTexture(GLuint texture);

	void addChild(std::shared_ptr<Model> child);

    std::shared_ptr<Mesh> mMesh;
    
	GLuint texture;
	
	glm::mat4 mTransform;

    glm::vec3 mPosition;
    glm::quat mRotation;

private:
	std::list<std::shared_ptr<Model>> children;
};


#endif
