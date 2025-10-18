#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class InputManager {
public:
    InputManager(GLFWwindow* window);
    bool IsKeyPressed(int key);
    bool IsMouseButtonPressed(int button);
    void GetMousePosition(double& xPos, double& yPos);
private:
    GLFWwindow* window;
};
