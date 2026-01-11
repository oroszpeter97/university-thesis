#include <glm/glm.hpp>
#include <thread>

#include <core/OpenGLContext.hpp>
#include <scenes/TestScene.hpp>

#include <iostream>
#include <chrono>

const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

int main() {
    OpenGLContext context(SCR_WIDTH, SCR_HEIGHT, "University Thesis");
    GLFWwindow* window = context.GetWindow();
    if (!window) return -1;

    Scene *currentScene = new TestScene(window);
    currentScene->SetUp();

    double lastFrameTime = glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {
        double currentFrameTime = glfwGetTime();
        float deltaTime = static_cast<float>(currentFrameTime - lastFrameTime);
        lastFrameTime = currentFrameTime;

        if (deltaTime > (1.0f / 60.0f)) {
            std::cout << "\033[1;31m[WARNING] Frame time dropped below 60 FPS: deltaTime = " << deltaTime << "\033[0m" << std::endl;
        }

        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        context.ProcessGlobalInput(window);

        currentScene->Update(deltaTime);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}
