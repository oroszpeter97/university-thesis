#pragma once

#include <core/GameObject.hpp>
#include <components/Transform.hpp>
#include <components/SpriteRenderer.hpp>

class Map : public GameObject
{
public:
    Map(std::string name, Scene* scene);
    ~Map();

    void OnSetUp() override;
    void OnUpdate(float deltaTime) override;

private:
protected:
};
