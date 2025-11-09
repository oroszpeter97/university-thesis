#pragma once

#include <vector>
#include <core/GameObject.hpp>
#include <components/Collider.hpp>
#include <components/Transform.hpp>
#include <iostream>

class CollisionManager { 
public:
    CollisionManager();
    ~CollisionManager();

    void CheckCollisions(std::vector<class GameObject*>& gameObjects, float deltaTime);

private:
    float time = 0.0f;
};