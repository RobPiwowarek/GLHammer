#ifndef RENDERER
#define RENDERER

#include "shaderManager.h"
#include "Camera.h"
#include "Model.h"
#include "Scene.h"
#include "GL\glew.h"
#include <gtc\type_ptr.hpp>

class Renderer{

public:
	void renderScene(std::shared_ptr<Camera>& camera, std::shared_ptr<Scene>& scene);
	void renderModel(std::shared_ptr<Model>& model);

	Renderer();

private:
    GLuint mMainShaderProgram;

	GLint mProjectionUniform;
	GLint mViewUniform;
	GLint mModelUniform;
};

#endif RENDERER