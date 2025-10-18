#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class OpenGLContext {
public:
    OpenGLContext(unsigned int width, unsigned int height, const char* title);
    ~OpenGLContext();
    GLFWwindow* getWindow() const;
    void processInput(GLFWwindow *window);

private:
    GLFWwindow* window;
};