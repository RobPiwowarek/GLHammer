
#include "Model.h"

Model::Model(std::shared_ptr<Mesh> mesh) : mMesh(std::move(mesh)) { this->texture = 0; }

void Model::setTexture(GLuint text) {
	this->texture = text;
}

void Model::setTransform(glm::mat4 transform) {
    mTransform = transform;
}

void Model::recalculateTransform() {
    glm::mat4 unit;
    auto translate = glm::translate(unit, mPosition);
    
	auto rotate = glm::toMat4(mRotation);

	mTransform = translate * rotate;

	for (auto && child : children){
		child->recalculateTransform();
	}
}

void Model::addChild(std::shared_ptr<Model> child){
	children.push_back(child);
}

void Model::setPosition(glm::vec3 position) {
    if (mPosition == position)
        return;
    mPosition = position;
    recalculateTransform();
}

void Model::setRotation(glm::vec3 rotationAxis, GLfloat angle) {
	if (angle == 0) return;

	mRotation = glm::angleAxis(angle, rotationAxis);

    recalculateTransform();
}

void Model::setRotation(glm::quat rotationQuat) {
	if (mRotation == rotationQuat) return;

	mRotation = rotationQuat;

	recalculateTransform();
}

void Model::joinRotation(glm::vec3 rotationAxis, GLfloat angle){
	if (angle == 0) return;

	mRotation = mRotation*glm::angleAxis(angle, rotationAxis);

	recalculateTransform();
}

