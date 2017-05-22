#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <iostream>
#include <vector>
#include <glm.hpp>
#include "gtc/matrix_transform.hpp"
#include <gtx/transform.hpp>
#include <gtc/type_ptr.hpp>

#include "shaderManager.h"
#include "MeshFactory.h"
#include "Model.h"
#include "Renderer.h"
#include "Scene.h"
#include "Camera.h"

using namespace std;

const GLuint WIDTH = 800, HEIGHT = 600;
GLFWwindow* init();

int main(){
	GLFWwindow* window = init();
	Renderer renderer;
	std::shared_ptr<Scene> mainScene = std::make_shared<Scene>();
	std::shared_ptr<Camera> camera = std::make_shared<Camera>(glm::vec3(4, 3, 3), glm::vec3(0, 0, 0));

	// test models
	std::shared_ptr<Model> testmodel = std::make_shared<Model>(MeshFactory::createCylinder(1, 1, 30));
	std::shared_ptr<Model> testmodel2 = std::make_shared<Model>(MeshFactory::createCube(1, 1, 1));
	std::shared_ptr<Model> testmodel3 = std::make_shared<Model>(MeshFactory::createCube(1, 1, 1));
	testmodel2->setPosition(glm::vec3(0, -1.5, 1));
	testmodel3->setPosition(glm::vec3(0, -1.5, -1));

	Texture texture("text.jpg");

	testmodel->setTexture(texture);

	mainScene->addModel(testmodel);
	mainScene->addModel(testmodel2);
	mainScene->addModel(testmodel3);

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
