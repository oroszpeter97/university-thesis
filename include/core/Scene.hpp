#pragma once

#include <core/GameObject.hpp>
#include <vector>

class Scene {
public:
    Scene();
    ~Scene();

    void AddGameObject(GameObject* gameObject);
    void RemoveGameObject(GameObject* gameObject);
    void UpdateGameObjects(float deltaTime);

    virtual void SetUp() = 0;

private:
    std::vector<GameObject*> gameObjects;
};