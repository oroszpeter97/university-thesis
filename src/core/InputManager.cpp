#include <core/InputManager.hpp>

InputManager::InputManager(GLFWwindow* window) : window(window) {
}

bool InputManager::IsKeyPressed(int key) {
    return glfwGetKey(window, key) == GLFW_PRESS;
}

bool InputManager::IsMouseButtonPressed(int button) {
    return glfwGetMouseButton(window, button) == GLFW_PRESS;
}

void InputManager::GetMousePosition(double& xPos, double& yPos) {
    glfwGetCursorPos(window, &xPos, &yPos);
}
