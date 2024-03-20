#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include "../../../initialicer/MINELLAX.H"

class EBO {

	public:
		GLuint ID;
		EBO(GLuint* indeces, GLsizeiptr size);

		void Bind();
		void Unbind();
		void Delete();
};

#endif