//vamos a hacer un clone de minecraft usando opengl y c++ 
//el juego se llamara TFG (Trabajo de Fin de Grado) MINELLAX

//EMPECEMOS CON EL CODIGO

//IMPORTAMOS LAS LIBRERIAS NECESARIAS
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//DEFINIMOS LAS CONSTANTES NECESARIAS
const GLint WIDTH = 1920, HEIGHT = 1080;

//DEFINIMOS LAS FUNCIONES NECESARIAS PERO COMO USAREMOS POO COMO PARADIGMA CREAREMOS UNA CLASE PARA CADA FUNCION
//ESTO NOS AYUDARA A TENER UN CODIGO MAS LIMPIO Y ORDENADO

//como este es el main.cpp no usaremos clases, pero si usaremos funciones

//FUNCION PARA INICIALIZAR GLFW
bool initGLFW(){
	//inicializamos glfw
	if (!glfwInit()){
		std::cout << "Error al inicializar GLFW" << std::endl;
		return false;
	}
	return true;
}

//FUNCION PARA CREAR UNA VENTANA
GLFWwindow* createWindow(const char* title, int width, int height){
	//creamos la ventana
	GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window){
		std::cout << "Error al crear la ventana" << std::endl;
		return NULL;
	}
	return window;
}

//FUNCION PARA INICIALIZAR GLEW
bool initGLEW(){
	//inicializamos glew
	if (glewInit() != GLEW_OK){
		std::cout << "Error al inicializar GLEW" << std::endl;
		return false;
	}
	return true;
}

//FUNCION PARA INICIALIZAR OPENGL

void initOpenGL(){
	//inicializamos opengl
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

//FUNCION PARA DIBUJAR

void draw(){
	//dibujamos
	glClear(GL_COLOR_BUFFER_BIT);
}

//FUNCION PARA ACTUALIZAR LA VENTANA

void update(GLFWwindow* window){
	//actualizamos la ventana
	glfwSwapBuffers(window);
	glfwPollEvents();
}

//FUNCION PARA CERRAR LA VENTANA

void closeWindow(GLFWwindow* window){
	//cerramos la ventana
	glfwDestroyWindow(window);
	glfwTerminate();
}

//FUNCION PRINCIPAL

int main(){
	//inicializamos glfw
	if (!initGLFW()){
		return -1;
	}

	//creamos la ventana
	GLFWwindow* window = createWindow("MINELLAX", WIDTH, HEIGHT);
	if (!window){
		glfwTerminate();
		return -1;
	}

	//inicializamos glew
	if (!initGLEW()){
		glfwDestroyWindow(window);
		glfwTerminate();
		return -1;
	}

	//inicializamos opengl
	initOpenGL();

	//bucle principal
	while (!glfwWindowShouldClose(window)){
		//dibujamos
		draw();

		//actualizamos la ventana
		update(window);
	}

	//cerramos la ventana
	closeWindow(window);
	return 0;
}



/*
Compilación iniciada a las 0:08...
1>------ Operación Compilar iniciada: Proyecto: TFG, configuración: Release x64 ------
1>MAIN.cpp
1>LINK : warning LNK4098: la biblioteca predeterminada'LIBCMT' entra en conflicto con otras bibliotecas; use la biblioteca /NODEFAULTLIB:biblioteca
1>Generando código
1>2 of 18 functions (11.1%) were compiled, the rest were copied from previous compilation.
1>  0 functions were new in current compilation
1>  0 functions had inline decision re-evaluated but remain unchanged
1>Generación de código finalizada
1>glew32s.lib(glew.obj) : warning LNK4099: no se encontró PDB '' con 'glew32s.lib(glew.obj)' o en ''; se vinculará el objeto sin tener en cuenta información de depuración
1>TFG.vcxproj -> E:\deberes\1º de DAM\PROGRAMACION\C++\TFG\x64\Release\TFG.exe
1>Compilación del proyecto "TFG.vcxproj" terminada.
========== Compilación: 1 correcto, 0 erróneo, 0 actualizado, 0 omitido ==========
========== Compilar completado a las 0:08 y tardó 01,904 segundos ==========
*/

//ME DA ESE PROBLEMA, PERO NO SE QUE ES COMO LO SULUCIONO??
