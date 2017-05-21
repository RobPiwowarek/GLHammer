#include "Scene.h"

Scene::Scene(){

}

void Scene::addModel(std::shared_ptr<Model> model) {
	models.push_back(model);
}

void Scene::removeModel(std::shared_ptr<Model> model) {
	models.remove(model);
}

void Scene::addLight(std::shared_ptr<Light> light) {
	lights.push_back(light);
}

void Scene::removeLight(std::shared_ptr<Light> light) {
	lights.remove(light);
}