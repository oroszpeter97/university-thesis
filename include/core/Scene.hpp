#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <core/GameObject.hpp>
#include <core/InputManager.hpp>
#include <core/CollisionManager.hpp>
#include <vector>

class Scene {
public:
    Scene(GLFWwindow* window);
    ~Scene();

    void AddGameObject(GameObject* gameObject);
    virtual void UpdateGameObjects(float deltaTime);

    virtual void SetUp() = 0;

private:
    GLFWwindow* window;
    CollisionManager collisionManager;

protected:
    InputManager inputManager;
    std::vector<GameObject*> gameObjects;
};