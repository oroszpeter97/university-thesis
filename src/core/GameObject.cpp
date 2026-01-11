#include <core/GameObject.hpp>

#include <iostream>

GameObject::GameObject() : _name("Unnamed"), _scene(nullptr)
{
}

GameObject::GameObject(const std::string &name, Scene *scene) : _name(name), _scene(scene)
{
}

GameObject::~GameObject()
{
}

void GameObject::SetUp()
{
    std::cout << "Setting up GameObject: " << _name << std::endl;
    OnSetUp();
}

void GameObject::Update(float deltaTime)
{
    for (auto &component : _components)
    {
        component->Update(deltaTime);
    }

    OnUpdate(deltaTime);
}

void GameObject::AddComponent(Component *component)
{
    _components.push_back(component);
}

Scene* GameObject::GetScene() const
{
    return _scene;
}

void GameObject::SetScene(Scene *scene)
{
    _scene = scene;
}

std::string GameObject::GetName() const
{
    return _name;
}

std::string GameObject::GetClassName() const
{
    return typeid(*this).name();
}

void GameObject::SetName(const std::string &name)
{
    _name = name;
}

std::vector<Component *> &GameObject::GetComponents()
{
    return _components;
}

std::vector<Component *> GameObject::GetComponentsByType(const std::string &type)
{
    std::cout << "Getting components of type: " << type << " from GameObject: " << _name << std::endl;
    std::vector<Component *> result;
    std::cout << "Total components in GameObject: " << _components.size() << std::endl;
    for (auto *component : _components)
    {
        std::cout << "Checking component of type: " << component->GetType() << std::endl;
        if (component->GetType() == type)
        {
            std::cout << "Matched component of type: " << type << std::endl;
            result.push_back(component);
        }
    }
    return result;
}
