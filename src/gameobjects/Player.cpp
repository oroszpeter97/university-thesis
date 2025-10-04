#include <gameobjects/Player.hpp>

Player::Player() {
    AddComponent(new Transform());
    AddComponent(new SpriteRenderer(glm::vec3(1000.0f, 360.0f, 0.0f), glm::vec3(1.0f), 0.0f));
}

Player::~Player() {
}

void Player::Update(float deltaTime) {
    UpdateComponents(deltaTime);
}
