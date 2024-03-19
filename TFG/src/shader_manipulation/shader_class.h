#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include "../initialicer/MINELLAX.H"

string get_file_contents(const char* filename);

class Shader {

public:
	GLuint ID;
	Shader(const char* vertexPath, const char* fragmentPath);

	void activate();
	void Delete();
};

#endif