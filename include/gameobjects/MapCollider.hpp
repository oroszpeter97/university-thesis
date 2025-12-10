#pragma once

#include "core/GameObject.hpp"

class MapCollider : public GameObject {
public:
    MapCollider();
    void Update(float deltaTime) override;
};