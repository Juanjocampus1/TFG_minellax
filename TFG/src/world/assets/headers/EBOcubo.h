#ifndef EBOCUBO_H
#define EBOCUBO_H

#include "../../../initialicer/MINELLAX.H"


class EBOCubo {

	public:
		GLuint ID;
		EBOCubo(GLuint* indeces, GLsizei size);

		void Bind();
		void Unbind();
		void Delete();
};

#endif