#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class OpenGLContext {
public:
    OpenGLContext(unsigned int width, unsigned int height, const char* title);
    ~OpenGLContext();
    GLFWwindow* getWindow() const;
    void processInput(GLFWwindow *window);

private:
    GLFWwindow* window;
};