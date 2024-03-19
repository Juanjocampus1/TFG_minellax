/*#include "camera.h"

Camera::Camera(float width, float height, glm::vec3 position ) {

	Camera::width = width;
	Camera::height = height;
	Position = position;

}

void Camera::matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform) {

	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(Position, Position + Orientation, Up);
	projection = glm::perspective(glm::radians(FOVdeg), width / height, nearPlane, farPlane);

}*/