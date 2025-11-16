#include <gameobjects/Player.hpp>

Player::Player(InputManager& inputManager) : GameObject() {
    AddComponent(new Transform());
    AddComponent(new SpriteRenderer(static_cast<Transform&>(*components[0]), "../resources/Player.png"));
    AddComponent(new Script(static_cast<Transform&>(*components[0]), inputManager));
    AddComponent(new Collider(glm::vec2(0.0f, 0.0f), glm::vec2(32.0f, 32.0f)));
    Collider* collider = dynamic_cast<Collider*>(components[2]);
    if (collider) {
        collider->SetStatic(true);
    }
}

Player::~Player() {
}

void Player::Update(float deltaTime) {
    SpriteRenderer* spriteRenderer = dynamic_cast<SpriteRenderer*>(components[1]);
    Transform* transform = dynamic_cast<Transform*>(components[0]);
    if (spriteRenderer && transform) {
        spriteRenderer->UpdateViewPosition(glm::vec3(-transform->GetPosition().x, -transform->GetPosition().y, -20.0f));
    }
    UpdateComponents(deltaTime);
}
