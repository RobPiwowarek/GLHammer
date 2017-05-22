#include "Texture.h"
#include <SOIL.h>
#include <iostream>

Texture::Texture(std::string file) {
	int width, height;
	unsigned char* image;
	GLuint texture;

	image = SOIL_load_image(file.c_str(), &width, &height, 0, SOIL_LOAD_RGB);

	if (image == nullptr)
		throw std::runtime_error("Failed to load texture file: " + std::string(file));

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	SOIL_free_image_data(image);

	this->mTextureID = texture;
}