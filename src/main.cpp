#include "pch.h"

int main() {
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, true);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Game Engine", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glewExperimental = true;
    glewInit();
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

		// Code goes here

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
