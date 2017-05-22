#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <gtc/constants.hpp>
#include <cmath>
#include <geometric.hpp>
#include "MeshFactory.h"

std::shared_ptr<Mesh> MeshFactory::createPlane(GLfloat w, GLfloat d) {
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices{0,1,2,1,3,2};
    vertices.emplace_back(glm::vec3(-0.5 * w, -0.5 * d, 0), glm::vec3(0, 0, 1), glm::vec2(0, 0));
    vertices.emplace_back(glm::vec3(0.5 * w, -0.5 * d, 0), glm::vec3(0, 0, 1), glm::vec2(1, 0));
    vertices.emplace_back(glm::vec3(-0.5 * w, 0.5 * d, 0), glm::vec3(0, 0, 1), glm::vec2(0, 1));
    vertices.emplace_back(glm::vec3(0.5 * w, 0.5 * d, 0), glm::vec3(0, 0, 1), glm::vec2(1, 1));

    return std::make_shared<Mesh>(std::move(vertices), std::move(indices));
}


std::shared_ptr<Mesh> MeshFactory::createCube(GLfloat w, GLfloat h, GLfloat d) {

    std::vector<Vertex> vertices;
    std::vector<GLuint> indices{0, 1, 2, 2, 1, 3, 4, 5, 6, 6, 5, 7, 8, 9, 10, 10, 9, 11, 12, 13, 14, 14, 13, 15, 16, 17,
                                18, 18,
                                17, 19, 20, 21, 22, 22, 21, 23,};
    vertices.emplace_back(glm::vec3(-0.5 * w, -0.5 * h, 0.5 * d), glm::vec3(0, 0, 1), glm::vec2(0, 0));
    vertices.emplace_back(glm::vec3(0.5 * w, -0.5 * h, 0.5 * d), glm::vec3(0, 0, 1), glm::vec2(1, 0));
    vertices.emplace_back(glm::vec3(-0.5 * w, 0.5 * h, 0.5 * d), glm::vec3(0, 0, 1), glm::vec2(0, 1));
    vertices.emplace_back(glm::vec3(0.5 * w, 0.5 * h, 0.5 * d), glm::vec3(0, 0, 1), glm::vec2(1, 1));
    vertices.emplace_back(glm::vec3(-0.5 * w, 0.5 * h, -0.5 * d), glm::vec3(0, 0, -1), glm::vec2(1, 1));
    vertices.emplace_back(glm::vec3(0.5 * w, 0.5 * h, -0.5 * d), glm::vec3(0, 0, -1), glm::vec2(0, 1));
    vertices.emplace_back(glm::vec3(-0.5 * w, -0.5 * h, -0.5 * d), glm::vec3(0, 0, -1), glm::vec2(1, 0));
    vertices.emplace_back(glm::vec3(0.5 * w, -0.5 * h, -0.5 * d), glm::vec3(0, 0, -1), glm::vec2(0, 0));
    vertices.emplace_back(glm::vec3(-0.5 * w, 0.5 * h, 0.5 * d), glm::vec3(0, 1, 0), glm::vec2(0, 0));
    vertices.emplace_back(glm::vec3(0.5 * w, 0.5 * h, 0.5 * d), glm::vec3(0, 1, 0), glm::vec2(1, 0));
    vertices.emplace_back(glm::vec3(-0.5 * w, 0.5 * h, -0.5 * d), glm::vec3(0, 1, 0), glm::vec2(0, 1));
    vertices.emplace_back(glm::vec3(0.5 * w, 0.5 * h, -0.5 * d), glm::vec3(0, 1, 0), glm::vec2(1, 1));
    vertices.emplace_back(glm::vec3(-0.5 * w, -0.5 * h, -0.5 * d), glm::vec3(0, -1, 0), glm::vec2(0, 0));
    vertices.emplace_back(glm::vec3(0.5 * w, -0.5 * h, -0.5 * d), glm::vec3(0, -1, 0), glm::vec2(1, 0));
    vertices.emplace_back(glm::vec3(-0.5 * w, -0.5 * h, 0.5 * d), glm::vec3(0, -1, 0), glm::vec2(0, 1));
    vertices.emplace_back(glm::vec3(0.5 * w, -0.5 * h, 0.5 * d), glm::vec3(0, -1, 0), glm::vec2(1, 1));
    vertices.emplace_back(glm::vec3(0.5 * w, -0.5 * h, 0.5 * d), glm::vec3(1, 0, 0), glm::vec2(0, 0));
    vertices.emplace_back(glm::vec3(0.5 * w, -0.5 * h, -0.5 * d), glm::vec3(1, 0, 0), glm::vec2(1, 0));
    vertices.emplace_back(glm::vec3(0.5 * w, 0.5 * h, 0.5 * d), glm::vec3(1, 0, 0), glm::vec2(0, 1));
    vertices.emplace_back(glm::vec3(0.5 * w, 0.5 * h, -0.5 * d), glm::vec3(1, 0, 0), glm::vec2(1, 1));
    vertices.emplace_back(glm::vec3(-0.5 * w, -0.5 * h, -0.5 * d), glm::vec3(-1, 0, 0), glm::vec2(0, 0));
    vertices.emplace_back(glm::vec3(-0.5 * w, -0.5 * h, 0.5 * d), glm::vec3(-1, 0, 0), glm::vec2(1, 0));
    vertices.emplace_back(glm::vec3(-0.5 * w, 0.5 * h, -0.5 * d), glm::vec3(-1, 0, 0), glm::vec2(0, 1));
    vertices.emplace_back(glm::vec3(-0.5 * w, 0.5 * h, 0.5 * d), glm::vec3(-1, 0, 0), glm::vec2(1, 1));

    return std::make_shared<Mesh>(std::move(vertices), std::move(indices));
}

std::shared_ptr<Mesh> MeshFactory::createCylinder(GLfloat r, GLfloat h, GLuint sides) {

	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	float deltaAngle = glm::two_pi<float>() / sides;

	// side indices
	for (GLuint i = 0; i < sides - 1; ++i) {
		indices.emplace_back(i);
		indices.emplace_back(i + 1);
		indices.emplace_back(sides + i);

		indices.emplace_back(sides + i);
		indices.emplace_back(sides + i + 1);
		indices.emplace_back(i + 1);
	}

	// base indices
	for (GLuint i = 0; i < sides - 1; ++i) {
		indices.emplace_back(0);
		indices.emplace_back(i+1);
		indices.emplace_back(i+2);

		indices.emplace_back(sides+i);
		indices.emplace_back(sides+i+1);
		indices.emplace_back(sides+i+2);
	}

	indices.emplace_back(sides);
	indices.emplace_back(0);
	indices.emplace_back(2 * sides);

	indices.emplace_back(2 * sides);
	indices.emplace_back(0);
	indices.emplace_back(sides+1);

	// vertices
	for (GLuint i = 0; i < sides; ++i) {
		float x = r * std::cos(deltaAngle * i);
		float y = r * std::sin(deltaAngle * i);

		vertices.emplace_back(glm::vec3(x, y, -h / 2), glm::normalize(glm::vec3(x, y, 0)), glm::vec2((float)i / sides, 0));
	}

	for (GLuint i = 0; i < sides; ++i) {
		float x = r * std::cos(deltaAngle * i);
		float y = r * std::sin(deltaAngle * i);

		vertices.emplace_back(glm::vec3(x, y, h / 2), glm::normalize(glm::vec3(x, y, 0)), glm::vec2((float)i / sides, 1));
	}

    return std::make_shared<Mesh>(std::move(vertices), std::move(indices));
}
