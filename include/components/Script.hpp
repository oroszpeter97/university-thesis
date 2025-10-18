#pragma once

#include <core/Component.hpp>
#include <components/Transform.hpp>
#include <core/InputManager.hpp>

class Script : public Component {
public:
    Script(Transform& transform, InputManager& inputManager);
    ~Script();

    void Update(float deltaTime) override;

private:
    float elapsedTime;
    Transform& transform;
    InputManager& inputManager;
};