#include "MINELLAX.H"
#include "../resolution/selector_resolucion.h"

GLFWwindow* window;

void errorCallback(int error, const char* description) {
    cerr << "Error: " << description <<endl;
}

int main(void) {
    glfwSetErrorCallback(errorCallback);

    if (!glfwInit())
        return -1;

    const int initialWidth = 1920, initialHeight = 1080;
    window = glfwCreateWindow(initialWidth, initialHeight, "TFG", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        exit(-1);

    float positions[6] = {
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

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        keyboard(key, action);
        });

    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
