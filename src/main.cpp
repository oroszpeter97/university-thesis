#include <glm/glm.hpp>

#include <OpenGLContext.h>

#include <iostream>

const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

int main() {
    OpenGLContext context(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL");
    GLFWwindow* window = context.getWindow();
    if (!window) return -1;

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        context.processInput(window);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}
