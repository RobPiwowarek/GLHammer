#ifndef GLPRESS_MESHFACTORY_H
#define GLPRESS_MESHFACTORY_H


#include "Mesh.h"

class MeshFactory {
public:
    static std::shared_ptr<Mesh> createPlane(GLfloat w, GLfloat d);
    static std::shared_ptr<Mesh> createCube(GLfloat w, GLfloat h, GLfloat d);
	static std::shared_ptr<Mesh> createCylinder(GLfloat r, GLfloat h, GLuint sides);

};


#endif //GLPRESS_MESHFACTORY_H
