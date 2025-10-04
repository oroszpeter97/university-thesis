#include <gameobjects/Player.hpp>

Player::Player() {
    AddComponent(new Transform());
    AddComponent(new SpriteRenderer());
}

Player::~Player() {
}

void Player::Update(float deltaTime) {
    UpdateComponents(deltaTime);
}
