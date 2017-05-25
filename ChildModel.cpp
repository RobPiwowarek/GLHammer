#include "ChildModel.h"

ChildModel::ChildModel(std::shared_ptr<Mesh> mesh, std::shared_ptr<Model> parent) : Model(std::move(mesh)){
	this->parent = parent;
	
}

void ChildModel::recalculateTransform(){

	glm::mat4 unit;
	auto rotate = glm::toMat4(this->mRotation);
	auto translate = glm::translate(unit, this->mPosition);
	rotate = glm::toMat4(parent->mRotation) * translate * rotate;
	translate = glm::translate(unit, parent->mPosition);
	this->mTransform = translate * rotate;
}

/*

void ChildModel::setPosition(glm::vec3 position){

}

void ChildModel::setRotation(glm::vec3 rotationAxis, GLfloat angle){

}

void ChildModel::setTexture(GLuint texture){

}

*/



