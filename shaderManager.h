#ifndef SHADERMANAGER
#define SHADERMANAGER

#include <gl\glew.h>

class ShaderManager
{
	GLuint program_id; 	// The program ID
public:
	// Constructor reads and builds the shader
	ShaderManager(const GLchar* vertexPath, const GLchar* fragmentPath);

	// Use the program
	void Use() const
	{
		glUseProgram(get_programID());
	}

	// returns program ID
	GLuint get_programID() const
	{
		return program_id;
	}
};

#endif