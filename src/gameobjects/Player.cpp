#include <gameobjects/Player.hpp>

Player::Player() {
    AddComponent(new Transform());
}

Player::~Player() {
}

void Player::Update(float deltaTime) {
    
}
