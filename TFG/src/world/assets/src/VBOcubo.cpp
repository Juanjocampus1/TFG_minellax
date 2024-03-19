#include "../headers/VBOcubo.h"

VBOCubo::VBOCubo(GLfloat* vertices, GLsizei size) {
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VBOCubo::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBOCubo::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBOCubo::Delete() {
	glDeleteBuffers(1, &ID);
}