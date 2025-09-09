#include <gameobjects/Player.hpp>

Player::Player() {
    AddComponent(new Transform());
    std::cout << "Player GameObject started." << std::endl;
}

Player::~Player() {
}

void Player::Update(float deltaTime) {
}
