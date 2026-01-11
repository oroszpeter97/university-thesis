#include <gameobjects/Player.hpp>

Player::Player(std::string name, Scene* scene, InputManager &inputManager) : GameObject(name, scene)
{
    AddComponent(new Transform());
    Transform *transform = dynamic_cast<Transform *>(GetComponentsByType("Transform")[0]);
    AddComponent(new SpriteRenderer(*transform, GetScene(), "../resources/Player.png"));
    AddComponent(new PlayerScript(*transform, inputManager));
    AddComponent(new Collider(glm::vec2(0.0f, 0.0f), glm::vec2(32.0f, 32.0f)));
    Collider *collider = dynamic_cast<Collider *>(GetComponentsByType("Collider")[0]);
    if (collider)
    {
        collider->SetStatic(true);
    }
}

Player::~Player()
{
}

void Player::OnSetUp()
{
}

void Player::OnUpdate(float deltaTime)
{
}
