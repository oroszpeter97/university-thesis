#pragma once

#include <core/Component.hpp>
#include <components/Transform.hpp>
#include <core/InputManager.hpp>

class PlayerScript : public Component {
public:
    PlayerScript(Transform& transform, InputManager& inputManager);
    ~PlayerScript();

    void OnSetUp() override;
    void OnUpdate(float deltaTime) override;
    virtual std::string GetType() const override;

private:
    float _elapsedTime;
    Transform& _transform;
    InputManager& _inputManager;
};