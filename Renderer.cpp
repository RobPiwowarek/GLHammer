#include "Renderer.h" 

Renderer::Renderer() {

	ShaderManager theProgram("main.vert", "main.frag");

	mMainShaderProgram = theProgram.get_programID();

	mSamplerUniform = glGetUniformLocation(mMainShaderProgram, "ourTexture");

	mViewPosLoc = glGetUniformLocation(mMainShaderProgram, "viewPos");

	mProjectionUniform = glGetUniformLocation(mMainShaderProgram, "Projection");
	mViewUniform = glGetUniformLocation(mMainShaderProgram, "View");
	mModelUniform = glGetUniformLocation(mMainShaderProgram, "Model"); 

	
}

void Renderer::renderScene(std::shared_ptr<Camera>& camera, std::shared_ptr<Scene>& scene){

	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(mMainShaderProgram);

	glUniformMatrix4fv(mProjectionUniform, 1, GL_FALSE, glm::value_ptr(camera->mProjection));
	glUniformMatrix4fv(mViewUniform, 1, GL_FALSE, glm::value_ptr(camera->mView));

	for (auto&& light : scene->lights){
		glUniform3f(light->lightPosLoc, light->position.x, light->position.y, light->position.z);
		glUniform3f(light->lightColorLoc, light->color.x, light->color.y, light->color.z);
		glUniform3f(mViewPosLoc, camera->mPostion.x, camera->mPostion.y, camera->mPostion.z);
	}

	for (auto&& model : scene->models) {
		renderModel(model);
	}

}

void Renderer::renderModel(std::shared_ptr<Model>& model){

	glUniformMatrix4fv(mModelUniform, 1, GL_FALSE, glm::value_ptr(model->mTransform));

	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, model->texture);

	glUniform1i(mSamplerUniform, GL_TEXTURE0);

	model->mMesh->draw();

}

GLuint Renderer::getShaderProgramID(){
	return mMainShaderProgram;
}