#pragma once

#include <vector>
#include <core/GameObject.hpp>
#include <components/Collider.hpp>
#include <components/Transform.hpp>
#include <iostream>

class CollisionManager
{
public:
    CollisionManager();
    ~CollisionManager();

    void SetUp();
    void Update(std::vector<class GameObject *> &gameObjects, float deltaTime);

private:
    float _time = 0.0f;

protected:
};