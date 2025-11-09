#pragma once

#include <core/GameObject.hpp>
#include <components/Transform.hpp>
#include <components/SpriteRenderer.hpp>
#include <components/Collider.hpp>

class Box : public GameObject {
public:
    Box();
    ~Box();

    void Update(float deltaTime) override;

private:
};
