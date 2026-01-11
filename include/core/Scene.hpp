#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <core/GameObject.hpp>
#include <core/InputManager.hpp>
#include <core/CollisionManager.hpp>
#include <gameobjects/Camera.hpp>
#include <vector>

class Scene
{
public:
    Scene(GLFWwindow *window);
    ~Scene();

    void SetUp();
    void Update(float deltaTime);

    void AddGameObject(GameObject *gameObject);
    Camera *GetActiveCamera();
    void SetActiveCamera(Camera *camera);

private:
    GLFWwindow *_window;
    std::vector<GameObject *> _gameObjects;
    InputManager _inputManager;
    CollisionManager _collisionManager;
    Camera *_activeCamera = nullptr;

protected:
    virtual void OnSetUp() = 0;
    virtual void OnUpdate(float deltaTime) = 0;

    GLFWwindow *GetWindow();
    std::vector<GameObject *> &GetGameObjects();
    InputManager &GetInputManager();
    CollisionManager &GetCollisionManager();
    std::vector<GameObject *> GetGameObjectsByName(const std::string &name);
    std::vector<GameObject *> GetGameObjectsByType(const std::string &type);
};