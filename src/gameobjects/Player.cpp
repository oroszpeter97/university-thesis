#include <gameobjects/Player.hpp>

Player::Player(InputManager& inputManager) : GameObject() {
    AddComponent(new Transform());
    AddComponent(new SpriteRenderer(static_cast<Transform&>(*components[0])));
    AddComponent(new Script(static_cast<Transform&>(*components[0]), inputManager));
    AddComponent(new Collider(glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f)));
}

Player::~Player() {
}

void Player::Update(float deltaTime) {
    UpdateComponents(deltaTime);
}
