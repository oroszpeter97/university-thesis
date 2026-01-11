#include <core/InputManager.hpp>

InputManager::InputManager(GLFWwindow *window) : _window(window)
{
}

InputManager::~InputManager()
{
}

bool InputManager::IsKeyPressed(int key)
{
    return glfwGetKey(_window, key) == GLFW_PRESS;
}

bool InputManager::IsMouseButtonPressed(int button)
{
    return glfwGetMouseButton(_window, button) == GLFW_PRESS;
}

void InputManager::GetMousePosition(double &xPos, double &yPos)
{
    glfwGetCursorPos(_window, &xPos, &yPos);
}
