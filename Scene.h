#ifndef SCENE
#define SCENE

#include <list>
#include <GL/glew.h>

#include "Model.h"
#include "Light.h"

class Scene{
	friend class Renderer;

private:
	std::list<std::shared_ptr<Model>> models;
	std::list<std::shared_ptr<Light>> lights;

public:
	void addModel(std::shared_ptr<Model> model);
	void removeModel(std::shared_ptr<Model> model);
	void addLight(std::shared_ptr<Light> light);
	void removeLight(std::shared_ptr<Light> light);
	Scene();

};

#endif