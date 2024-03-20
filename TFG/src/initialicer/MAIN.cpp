#include<iostream>
#include<gl/glew.h>
#include<GLFW/glfw3.h>

#include "../resolution/selector_resolucion.h"
#include"../shader_manipulation/shaderClass.h"
#include"../world/assets/headers/VAO.h"
#include"../world/assets/headers/VBO.h"
#include"../world/assets/headers/EBO.h"

// Vertices coordinates
GLfloat vertices[] ={
    -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
    0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
    0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
    -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
    0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
    0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
};

// Indices for vertices order
GLuint indices[] ={
    0, 3, 5, // Lower left triangle
    3, 2, 4, // Lower right triangle
    5, 4, 1 // Upper triangle
};

GLFWwindow* window;

void errorCallback(int error, const char* description) {
    cerr << "Error: " << description <<endl;
}

int main(void) {
    glfwSetErrorCallback(errorCallback);

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const int initialWidth = 1920, initialHeight = 1080;
    window = glfwCreateWindow(initialWidth, initialHeight, "TFG", NULL, NULL);

    if (window == NULL){
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        exit(-1);

    glViewport(0, 0, initialWidth, initialHeight);

    try {
        // Generates Shader object using shaders defualt.vert and default.frag
        Shader shaderProgram("src/shaders/default.vert", "src/shaders/default.frag");

        // Generates Vertex Array Object and binds it
        VAO VAO1;
        VAO1.Bind();

        // Generates Vertex Buffer Object and links it to vertices
        VBO VBO1(vertices, sizeof(vertices));
        // Generates Element Buffer Object and links it to indices
        EBO EBO1(indices, sizeof(indices));

        // Links VBO to VAO
        VAO1.LinkVBO(VBO1, 0);
        // Unbind all to prevent accidentally modifying them
        VAO1.Unbind();
        VBO1.Unbind();
        EBO1.Unbind();
    


    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        keyboard(key, action);
    });

    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Activate();
        // Bind the VAO so OpenGL knows to use it
        VAO1.Bind();

        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
    }

    catch (const exception& e) {
        cerr << "Excepción capturada: " << e.what() << '\n';
        return -1;
    }
}

















/*float positions[6] = {
        -0.5f, -0.5f,
        0.0f, 0.5f,
        0.5f, -0.5f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);*/