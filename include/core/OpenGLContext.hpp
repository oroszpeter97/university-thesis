#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <tools/Logger.hpp>
#include <stb_image.h>

class OpenGLContext
{
    public:
        OpenGLContext(unsigned int width, unsigned int height, const char *title);
        ~OpenGLContext();

        GLFWwindow *GetWindow() const;

    private:
        GLFWwindow *_window;
        Logger& _logger;

        static void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);
};