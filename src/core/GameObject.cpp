#include <core/GameObject.hpp>

GameObject::GameObject() {
}

GameObject::~GameObject() {
}

void GameObject::UpdateComponents(float deltaTime) {
    for (auto& component : components) {
        component->Update(deltaTime);
    }
}

void GameObject::AddComponent(Component* component) {
    components.push_back(component);
}
