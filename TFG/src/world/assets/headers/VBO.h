#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include "../../../initialicer/MINELLAX.H"


class VBO {

	public:
		GLuint ID;
		VBO(GLfloat* vertices, ptrdiff_t size);

		void Bind();
		void Unbind();
		void Delete();
};

#endif