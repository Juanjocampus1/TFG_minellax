#ifndef VBOCUBO_H
#define VBOCUBO_H

#include "../../../initialicer/MINELLAX.H"


class VBOCubo {

	public:
		GLuint ID;
		VBOCubo(GLfloat* vertices, GLsizei size);

		void Bind();
		void Unbind();
		void Delete();
};

#endif