#pragma once

#include <core/GameObject.hpp>
#include <components/Transform.hpp>
#include <components/SpriteRenderer.hpp>
#include <components/Collider.hpp>

class Box : public GameObject {
public:
    Box(std::string name, Scene* scene = nullptr);
    ~Box();

    void OnSetUp() override;
    void OnUpdate(float deltaTime) override;

private:
protected:
};
