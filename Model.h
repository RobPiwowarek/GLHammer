#ifndef MODEL
#define MODEL

#include "Mesh.h"
#include "Texture.h"

class Model {
public:
    void setTransform(glm::mat4 transform);

    Model(std::shared_ptr<Mesh> mesh);

    void setPosition(glm::vec3 position);

    void setRotation(glm::vec3 rotation);

    void recalculateTransform();

	void setTexture(GLuint texture);

    std::shared_ptr<Mesh> mMesh;
    
	GLuint texture;
	
	glm::mat4 mTransform;

    glm::vec3 mPosition;
    glm::vec3 mRotation;
};


#endif
