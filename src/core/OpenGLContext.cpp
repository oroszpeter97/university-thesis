#include <core/OpenGLContext.hpp>
#include <stdexcept>

OpenGLContext::OpenGLContext(unsigned int width, unsigned int height, const char* title) : _logger(Logger::GetInstance()) {
    _logger.Log("Initializing OpenGL context", LogLevel::INFO);
    if (!glfwInit())
    {
        _logger.Log("Failed to initialize GLFW", LogLevel::ERROR);
        throw std::runtime_error("Failed to initialize GLFW");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (_window == nullptr)
    {
        _logger.Log("Failed to create GLFW window", LogLevel::ERROR);
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, FrameBufferSizeCallback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        _logger.Log("Failed to initialize GLAD", LogLevel::ERROR);
        glfwDestroyWindow(_window);
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLAD");
    }

    stbi_set_flip_vertically_on_load(true);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_STENCIL_TEST);  
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK); 
    _logger.Log("OpenGL context initialized successfully", LogLevel::INFO);
}

OpenGLContext::~OpenGLContext() {
    if (_window) {
        glfwDestroyWindow(_window);
    }
    glfwTerminate();
}

GLFWwindow* OpenGLContext::GetWindow() const {
    return _window;
}

void OpenGLContext::FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}