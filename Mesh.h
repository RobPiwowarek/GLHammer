#ifndef GLPRESS_MESH_H
#define GLPRESS_MESH_H

#include <vector>
#include <string>
#include <memory>
#include <GL/glew.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 textCoord;

    Vertex() {};

    Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 textCoord) : position(position), normal(normal), textCoord(textCoord) {}
};

class Mesh {
    friend class MeshFactory;

public:
    Mesh(std::vector<Vertex>&& vertices, std::vector<GLuint>&& indices);

    void draw();

	void setPosition(glm::vec3 position);

	void setRotation(glm::vec3 rotation);

	void setTransform(glm::mat4 transform);

private:

	void recalculateTransform();

    std::vector<Vertex> mVertices;
    std::vector<GLuint> mIndices;

	glm::mat4 mTransform;

	glm::vec3 mPosition;
	glm::vec3 mRotation;

    GLuint mVAO;
    GLuint mVBO;
    GLuint mEBO;

};


#endif //GLPRESS_MESH_H
