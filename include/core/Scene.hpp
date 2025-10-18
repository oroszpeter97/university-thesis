#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <core/GameObject.hpp>
#include <core/InputManager.hpp>
#include <vector>

class Scene {
public:
    Scene(GLFWwindow* window);
    ~Scene();

    void AddGameObject(GameObject* gameObject);
    void RemoveGameObject(GameObject* gameObject);
    void UpdateGameObjects(float deltaTime);

    virtual void SetUp() = 0;

private:
    std::vector<GameObject*> gameObjects;

protected:
    InputManager inputManager;
};