#include <scripts/PlayerScript.hpp>
#include <iostream>

PlayerScript::PlayerScript(Transform &transform, InputManager &inputManager)
    : Component(), _elapsedTime(0.0f), _transform(transform), _inputManager(inputManager)
{
}

PlayerScript::~PlayerScript()
{
}

void PlayerScript::OnSetUp()
{
}

void PlayerScript::OnUpdate(float deltaTime)
{
    const float moveSpeed = 400.0f;
    const float rotateSpeed = 50.0f;
    if (_inputManager.IsKeyPressed(GLFW_KEY_D))
    {
        _transform.SetPosition(_transform.GetPosition() + glm::vec3(moveSpeed * deltaTime, 0.0f, 0.0f));
    }
    if (_inputManager.IsKeyPressed(GLFW_KEY_A))
    {
        _transform.SetPosition(_transform.GetPosition() + glm::vec3(-moveSpeed * deltaTime, 0.0f, 0.0f));
    }
    if (_inputManager.IsKeyPressed(GLFW_KEY_W))
    {
        _transform.SetPosition(_transform.GetPosition() + glm::vec3(0.0f, moveSpeed * deltaTime, 0.0f));
    }
    if (_inputManager.IsKeyPressed(GLFW_KEY_S))
    {
        _transform.SetPosition(_transform.GetPosition() + glm::vec3(0.0f, -moveSpeed * deltaTime, 0.0f));
    }
    if (_inputManager.IsKeyPressed(GLFW_KEY_Q))
    {
        _transform.SetRotation(_transform.GetRotation() + glm::vec3(0.0f, 0.0f, rotateSpeed * deltaTime));
    }
    if (_inputManager.IsKeyPressed(GLFW_KEY_E))
    {
        _transform.SetRotation(_transform.GetRotation() + glm::vec3(0.0f, 0.0f, -rotateSpeed * deltaTime));
    }

    std::cout << "Player Position: (" << _transform.GetPosition().x << ", " << _transform.GetPosition().y << ", " << _transform.GetPosition().z << ")\n";
}

std::string PlayerScript::GetType() const
{
    return "PlayerScript";
}