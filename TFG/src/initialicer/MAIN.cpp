#include "MINELLAX.H"
#include "../resolution/selector_resolucion.h"

#include "../shader_manipulation/shader_class.h"
#include "../world/assets/headers/VAOcubo.h"
#include "../world/assets/headers/VBOcubo.h"
#include "../world/assets/headers/EBOcubo.h"

GLfloat vertices[] = {
    -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
    0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
    0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
    - 0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
    0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
    0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f
};

GLuint indices[] = {
    0, 3, 5,
    3, 2, 4,
    5, 4, 1
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

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        exit(-1);

    glViewport(0, 0, initialWidth, initialHeight);

    Shader shaderprogram("default.vert", "default.frag");

    VAOcubo VAOcube;
    VAOcube.Bind();

    VBOCubo VBOcube(vertices, sizeof(vertices));
    EBOCubo EBOcube(indices, sizeof(indices));

    VAOcube.linkVBOCubo(VBOcube, 0);
    VAOcube.Unbind();
    VBOcube.Unbind();
    EBOcube.Unbind();

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        keyboard(key, action);
        });

    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        
        glClear(GL_COLOR_BUFFER_BIT);

        shaderprogram.activate();
        VAOcube.Bind();

        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    VAOcube.Delete();
    VBOcube.Delete();
    EBOcube.Delete();
    shaderprogram.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
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