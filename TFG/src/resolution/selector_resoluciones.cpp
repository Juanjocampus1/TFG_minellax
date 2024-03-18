#include "selector_resolucion.h"
#include <iostream>

extern GLFWwindow* window; // Agregar la declaración externa de la ventana GLFW

vector<pair<int, int>> resolutions = {
    {800, 600},
    {1024, 768},
    {1280, 720},
    {1920, 1080},
    {2560, 1440},
    {3840, 2160},
    {7680, 4320}
};

int currentResolutionIndex = 0;

void changeResolution(int width, int height) {
    glfwSetWindowSize(window, width, height);
    glViewport(0, 0, width, height);
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Renderiza tu escena OpenGL aquí
    glfwSwapBuffers(window);
}

void keyboard(int key, int action) {
    if (action == GLFW_PRESS) {
        switch (key) {
        case GLFW_KEY_1:
        case GLFW_KEY_2:
        case GLFW_KEY_3:
        case GLFW_KEY_4:
        case GLFW_KEY_5:
        case GLFW_KEY_6:
        case GLFW_KEY_7:
            currentResolutionIndex = key - GLFW_KEY_1;
            if (currentResolutionIndex >= 0 && currentResolutionIndex < resolutions.size()) {
                int width = resolutions[currentResolutionIndex].first;
                int height = resolutions[currentResolutionIndex].second;
                changeResolution(width, height);
            }
            break;
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            break;
        default:
            break;
        }
    }
}
