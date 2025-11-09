#pragma once

#include <core/GameObject.hpp>
#include <components/Transform.hpp>
#include <components/SpriteRenderer.hpp>
#include <components/Script.hpp>
#include <core/InputManager.hpp>
#include <components/Collider.hpp>

class Player : public GameObject {
public:
    Player(InputManager& inputManager);
    ~Player();

    void Update(float deltaTime) override;

private:
};
