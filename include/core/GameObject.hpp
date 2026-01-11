#pragma once

#include <core/Component.hpp>
#include <vector>
#include <typeinfo>
#include <string>

class Scene;

class GameObject
{
public:
    GameObject();
    GameObject(const std::string &name, Scene* scene);
    ~GameObject();

    void SetUp();
    void Update(float deltaTime);

    void AddComponent(Component *component);
    Scene* GetScene() const;
    void SetScene(Scene* scene);
    std::string GetName() const;
    std::string GetClassName() const;
    void SetName(const std::string &name);
    std::vector<Component *> &GetComponents();
    std::vector<Component *> GetComponentsByType(const std::string &type);

private:
    std::vector<Component *> _components;
    std::string _name;
    Scene* _scene;

protected:
    virtual void OnSetUp() = 0;
    virtual void OnUpdate(float deltaTime) = 0;
};