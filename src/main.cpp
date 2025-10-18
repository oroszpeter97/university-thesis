#include <glm/glm.hpp>

#include <core/OpenGLContext.hpp>
#include <scenes/TestScene.hpp>

#include <iostream>

const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

int main() {
    OpenGLContext context(SCR_WIDTH, SCR_HEIGHT, "University Thesis");
    GLFWwindow* window = context.getWindow();
    if (!window) return -1;

    Scene *currentScene = new TestScene(window);

    double lastFrameTime = glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {
        double currentFrameTime = glfwGetTime();
        float deltaTime = static_cast<float>(currentFrameTime - lastFrameTime);
        lastFrameTime = currentFrameTime;

        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        context.processInput(window);

        currentScene->UpdateGameObjects(deltaTime);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}
