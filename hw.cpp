#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

#include "shaderManager.h"
#include "MeshFactory.h"
#include "Model.h"
#include "Renderer.h"
#include "Scene.h"
#include "Camera.h"
#include "Texture.h"
#include "Light.h"
#include "ChildModel.h"
#include "AnimationFrame.h"

using namespace std;

const GLuint WIDTH = 800, HEIGHT = 600;
GLFWwindow* init();

// Deltatime
GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
GLfloat lastFrame = 0.0f;  	// Time of last frame

GLfloat activeTime = 0.0f;  // from the start of animation till the end

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void do_movement(std::shared_ptr<Camera> camera);

std::shared_ptr<Camera> camera;
std::shared_ptr<Light> pointLight;

// Animations
std::vector<AnimationFrame> hammerAnimations;

glm::quat startingRotation = glm::angleAxis(2.0944f, glm::vec3(-0.57735f, -0.57735f, -0.57735f)); 
//glm::angleAxis(-glm::half_pi<float>(), glm::normalize(glm::vec3(1, 0, 0))) *  glm::angleAxis(-glm::half_pi<float>(), glm::normalize(glm::vec3(0, 0, 1)));
glm::quat leftCoinHammerRotation = glm::angleAxis(3.3078f, glm::vec3(-0.830181, 0.0556566, -0.554709));
// leftCoinHammerRotation = glm::angleAxis(-glm::half_pi<float>() / 4, glm::normalize(glm::vec3(0, -1, 0))) * glm::angleAxis(-glm::half_pi<float>()-0.2f , glm::normalize(glm::vec3(0, 0, 1))) * startingRotation;
glm::quat rightCoinHammerRotation = glm::angleAxis(3.25258f, glm::vec3(-0.553647 ,0.0831365, -0.828591));

int main(){
	GLFWwindow* window = init();
	glfwSetKeyCallback(window, key_callback);
	Renderer renderer;
	std::shared_ptr<Scene> mainScene = std::make_shared<Scene>();

	// camera

	camera = std::make_shared<Camera>(glm::vec3(0, 0, 0));

	camera->setDistance(10.0f);

	// test models
	std::shared_ptr<Model> hammerHandle = std::make_shared<Model>(MeshFactory::createCylinder(0.5, 6, 32));
	std::shared_ptr<Model> leftPad = std::make_shared<Model>(MeshFactory::createCube(1, 1, 1));
	std::shared_ptr<Model> rightPad = std::make_shared<Model>(MeshFactory::createCube(1, 1, 1));
	std::shared_ptr<Model> ground = std::make_shared<Model>(MeshFactory::createCube(10, 0.1, 10));
	std::shared_ptr<Model> leftCoin = std::make_shared<Model>(MeshFactory::createCylinder(0.5, 0.2, 32));
	std::shared_ptr<Model> leftCoinFace = std::make_shared<Model>(MeshFactory::createCircle(0.5, 32));
	std::shared_ptr<Model> rightCoin = std::make_shared<Model>(MeshFactory::createCylinder(0.5, 0.2, 32));
	std::shared_ptr<Model> rightCoinFace = std::make_shared<Model>(MeshFactory::createCircle(0.5, 32));
	std::shared_ptr<ChildModel> hammerHead = std::make_shared<ChildModel>(MeshFactory::createCube(1, 3, 1), hammerHandle);

	// set parent/children
	hammerHandle->addChild(hammerHead);

	// Positions

	leftPad->setPosition(glm::vec3(1.75, -2.5, 1));
	leftCoin->setPosition(glm::vec3(1.75, -2, 1));
	leftCoinFace->setPosition(glm::vec3(1.75, -1.88, 1));
	rightCoin->setPosition(glm::vec3(1.75, -2, -1));
	rightCoinFace->setPosition(glm::vec3(1.75, -1.88, -1));
	rightPad->setPosition(glm::vec3(1.75, -2.5, -1));
	ground->setPosition(glm::vec3(0, -3, 0));
	hammerHead->setPosition(glm::vec3(0, 0, 2));
	
	// Rotations

	leftCoin->setRotation(glm::normalize(glm::vec3(-1, 0, 0)), glm::half_pi<float>());
	leftCoinFace->setRotation(glm::normalize(glm::vec3(-1, 0, 0)), glm::half_pi<float>());
	rightCoin->setRotation(glm::normalize(glm::vec3(-1, 0, 0)), glm::half_pi<float>());
	rightCoinFace->setRotation(glm::normalize(glm::vec3(-1, 0, 0)), glm::half_pi<float>());
	hammerHandle->setRotation(startingRotation);

	// init animations

	hammerAnimations.emplace_back(0.0f, startingRotation);
	hammerAnimations.emplace_back(3.0f, leftCoinHammerRotation);
	hammerAnimations.emplace_back(5.0f, startingRotation);
	hammerAnimations.emplace_back(8.0f, rightCoinHammerRotation);
	hammerAnimations.emplace_back(10.0f, startingRotation);

	// Init textures

	Texture floorTexture("floor.jpg");
	Texture texture("text.jpg");
	Texture coinTexture("coin.jpg");
	Texture silver("silver.jpg");

	hammerHandle->setTexture(texture.getID());
	hammerHead->setTexture(silver.getID());
	leftPad->setTexture(texture.getID());
	rightPad->setTexture(texture.getID());
	leftCoin->setTexture(silver.getID());
	leftCoinFace->setTexture(coinTexture.getID());
	rightCoin->setTexture(silver.getID());
	rightCoinFace->setTexture(coinTexture.getID());
	ground->setTexture(floorTexture.getID());

	// Models to scene

	mainScene->addModel(hammerHead);
	mainScene->addModel(hammerHandle);
	mainScene->addModel(leftPad);
	mainScene->addModel(rightPad);
	mainScene->addModel(ground);
	mainScene->addModel(leftCoin);
	mainScene->addModel(leftCoinFace);
	mainScene->addModel(rightCoin);
	mainScene->addModel(rightCoinFace);

	// Lights

	pointLight = std::make_shared<Light>(renderer.getShaderProgramID(), glm::vec3(8, 6, 10), glm::vec3(1, 1, 1));

	mainScene->addLight(pointLight);

	// Game Loop

	while (!glfwWindowShouldClose(window))
	{
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glfwPollEvents();

		// Animations

		AnimationFrame f1, f2;
		GLfloat param;

		activeTime += deltaTime;
		activeTime = (float)fmod(activeTime, 12);

		std::vector<AnimationFrame> tempAnim = std::vector<AnimationFrame>(hammerAnimations);
		for (auto iter = tempAnim.begin(); iter != tempAnim.end(); ++iter)
		{
			if (iter->time > activeTime) {
				f2 = *iter;
				f1 = *(iter - 1);
				param = (activeTime - f1.time) / (f2.time - f1.time);
				hammerHandle->setRotation(glm::mix(f1.rotation, f2.rotation, param));
				break;
			}
		} 
		
		// Rendering

		renderer.renderScene(camera, mainScene); 
		
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    GLfloat cameraSpeed = 0.75f * deltaTime;

	if (key == GLFW_KEY_W)
		camera->setVAngle(camera->getVAngle() + cameraSpeed);
	if (key == GLFW_KEY_S)
		camera->setVAngle(camera->getVAngle() - cameraSpeed);
	if (key == GLFW_KEY_A)
		camera->setHAngle(camera->getHAngle() + cameraSpeed);
	if (key == GLFW_KEY_D)
		camera->setHAngle(camera->getHAngle() - cameraSpeed);
	if (key == GLFW_KEY_SPACE)
		camera->setDistance(camera->getDistance() + cameraSpeed);
	if (key == GLFW_KEY_BACKSPACE)
		camera->setDistance(camera->getDistance() - cameraSpeed);
	if (key == GLFW_KEY_EQUAL)
		pointLight->strength += cameraSpeed;
	if (key == GLFW_KEY_MINUS)
		pointLight->strength -= cameraSpeed;

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
