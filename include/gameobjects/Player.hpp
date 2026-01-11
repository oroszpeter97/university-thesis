#pragma once

#include <core/GameObject.hpp>
#include <components/Transform.hpp>
#include <components/SpriteRenderer.hpp>
#include <core/InputManager.hpp>
#include <components/Collider.hpp>
#include <scripts/PlayerScript.hpp>

class Player : public GameObject
{
public:
    Player(std::string name, Scene* scene, InputManager &inputManager);
    ~Player();

    void OnSetUp() override;
    void OnUpdate(float deltaTime) override;

private:
protected:
};
