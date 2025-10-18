#include <gameobjects/Player.hpp>

Player::Player(InputManager& inputManager) : GameObject() {
    AddComponent(new Transform());
    AddComponent(new SpriteRenderer(static_cast<Transform&>(*components[0])));
    AddComponent(new Script(static_cast<Transform&>(*components[0]), inputManager));
}

Player::~Player() {
}

void Player::Update(float deltaTime) {
    UpdateComponents(deltaTime);
}
