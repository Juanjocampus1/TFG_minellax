#ifndef VAOCUBO_CLASS_H
#define VAOCUBO_CLASS_H

#include "../../../initialicer/MINELLAX.H"
#include "VBOcubo.h"

class VAOcubo {

	public:
		GLuint ID;
		VAOcubo();

		void linkVBOCubo(VBOCubo VBOCubo, GLuint layout);
		void Bind();
		void Unbind();
		void Delete();

};

#endif VAOCUBO_CLASS_H
