#pragma once

#include <core/Component.hpp>
#include <vector>
#include <typeinfo>
#include <string>

class GameObject {
public:
    GameObject();
    ~GameObject();
    void UpdateComponents(float deltaTime);
    void AddComponent(Component* component);
    std::vector<Component*>& GetComponents() { return components; }
    virtual std::string GetClassName() const {
        return typeid(*this).name();
    }

    virtual void Update(float deltaTime) = 0;

protected:
    std::vector<Component*> components;
};