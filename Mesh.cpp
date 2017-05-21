#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Mesh.h"
#include <glm.hpp>
#include "gtc/matrix_transform.hpp"

Mesh::Mesh(std::vector<Vertex>&& vertices, std::vector<GLuint>&& indices) : mVertices(vertices), mIndices(indices) {
    glGenVertexArrays(1, &mVAO);
    glGenBuffers(1, &mVBO);
    glGenBuffers(1, &mEBO);

    glBindVertexArray(mVAO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);

    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(Vertex), &mVertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndices.size() * sizeof(GLuint), &mIndices[0], GL_STATIC_DRAW);

    // Vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) 0);
    //normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) offsetof(Vertex, normal));
    // Texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) offsetof(Vertex, textCoord));

    glBindVertexArray(0);
}

void Mesh::draw() {
    glBindVertexArray(mVAO);
    glDrawElements(GL_TRIANGLES, (GLsizei) mIndices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Mesh::recalculateTransform() {
	glm::mat4 unit;
	auto translate = glm::translate(unit, mPosition);
	auto rotate = glm::rotate(translate, mRotation.x, glm::vec3(1, 0, 0));
	rotate = glm::rotate(rotate, mRotation.y, glm::vec3(0, 1, 0));
	mTransform = glm::rotate(rotate, mRotation.z, glm::vec3(0, 0, 1));
}

void Mesh::setPosition(glm::vec3 position) {
	if (mPosition == position)
		return;
	mPosition = position;
	recalculateTransform();
}

void Mesh::setRotation(glm::vec3 rotation) {
	if (mRotation == rotation)
		return;
	mRotation = rotation;
	recalculateTransform();
}



