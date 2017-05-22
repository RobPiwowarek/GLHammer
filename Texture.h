#ifndef TEXTURE
#define TEXTURE

#include <GL/glew.h>
#include <string>

class Texture{
public:
	Texture(std::string file);

	GLuint getID() { return mTextureID; }
private:
	GLuint mTextureID;

};

#endif