#pragma once

#include <core/GameObject.hpp>
#include <components/Transform.hpp>
#include <components/SpriteRenderer.hpp>
#include <components/Collider.hpp>

class Box2 : public GameObject {
public:
    Box2();
    ~Box2();

    void Update(float deltaTime) override;

private:
};
