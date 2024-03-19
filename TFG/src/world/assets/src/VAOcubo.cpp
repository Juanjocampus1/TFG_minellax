#include "../headers/VAOcubo.h"

VAOcubo::VAOcubo() {
	glGenVertexArrays(1, &ID);
}

void VAOcubo::linkVBOCubo(VBOCubo VBOCubo, GLuint layout) {
	VBOCubo.Bind();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(layout);
	VBOCubo.Unbind();
}

void VAOcubo::Bind() {
	glBindVertexArray(ID);
}

void VAOcubo::Unbind() {
	glBindVertexArray(0);
}

void VAOcubo::Delete() {
	glDeleteVertexArrays(1, &ID);
}