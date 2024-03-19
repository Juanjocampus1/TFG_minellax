/*#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include "../initialicer/MINELLAX.H"

class Camera {

	public:
		glm::vec3 position;
		glm::vec3 orientation = glm::vec3(0.0f,0.0f,-1.0f);
		glm::vec3 up = glm::vec3(0.0f,1.0f,0.0f);

		float width;
		float height;

		float speed = 0.0f;
		float sensitivity = 100.0f;

		Camera(glm::vec3 position, float width, float height);

		void matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform);
		void inputs(GLFWwindow* window);

#endif 
*/
