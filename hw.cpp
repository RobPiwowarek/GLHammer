#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shaderManager.h"
#include "MeshFactory.h"
#include "Model.h"
#include "Renderer.h"
#include "Scene.h"
#include "Camera.h"
#include "Texture.h"

using namespace std;

const GLuint WIDTH = 800, HEIGHT = 600;
GLFWwindow* init();

int main(){
	GLFWwindow* window = init();
	Renderer renderer;
	std::shared_ptr<Scene> mainScene = std::make_shared<Scene>();
	std::shared_ptr<Camera> camera = std::make_shared<Camera>(glm::vec3(8, 6, 10), glm::vec3(0, 0, 0));

	// test models
	std::shared_ptr<Model> hammerHandle = std::make_shared<Model>(MeshFactory::createCylinder(0.5, 6, 32));
	std::shared_ptr<Model> leftPad = std::make_shared<Model>(MeshFactory::createCube(1, 1, 1));
	std::shared_ptr<Model> rightPad = std::make_shared<Model>(MeshFactory::createCube(1, 1, 1));
	std::shared_ptr<Model> ground = std::make_shared<Model>(MeshFactory::createCube(10, 0, 10));

	leftPad->setPosition(glm::vec3(4, -2.5, 1));
	rightPad->setPosition(glm::vec3(4, -2.5, -1));
	ground->setPosition(glm::vec3(0, -3, 0));

	hammerHandle->setRotation(glm::vec3(-glm::half_pi<float>(), 0.5, 0));

	Texture texture("text.jpg");

	hammerHandle->setTexture(texture.getID());
	leftPad->setTexture(texture.getID());
	rightPad->setTexture(texture.getID());

	mainScene->addModel(hammerHandle);
	mainScene->addModel(leftPad);
	mainScene->addModel(rightPad);
	mainScene->addModel(ground);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		renderer.renderScene(camera, mainScene); 
		
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

GLFWwindow* init(){

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(1024, 800, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		throw "Failed to create GLFW window";
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		throw "Failed to initialize GLEW";
	}

	glEnable(GL_DEPTH_TEST);

	return window;
}
