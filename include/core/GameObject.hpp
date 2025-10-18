#pragma once

#include <core/Component.hpp>
#include <vector>

class GameObject {
public:
    GameObject();
    ~GameObject();
    void UpdateComponents(float deltaTime);
    void AddComponent(Component* component);

    virtual void Update(float deltaTime) = 0;

protected:
    std::vector<Component*> components;
};