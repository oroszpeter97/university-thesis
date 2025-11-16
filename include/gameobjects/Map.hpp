#pragma once

#include <core/GameObject.hpp>
#include <components/Transform.hpp>
#include <components/SpriteRenderer.hpp>

class Map : public GameObject {
public:
    Map();
    ~Map();

    void Update(float deltaTime) override;

private:
};
