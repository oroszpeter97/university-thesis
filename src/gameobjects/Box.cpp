#include <gameobjects/Box.hpp>

Box::Box() {
    AddComponent(new Transform());
    AddComponent(new SpriteRenderer(static_cast<Transform&>(*components[0]), "../resources/textures/container.jpg"));
    AddComponent(new Collider(glm::vec2(0.0f, 0.0f), glm::vec2(32.0f, 32.0f)));
    Collider* collider = dynamic_cast<Collider*>(components[2]);
    if (collider) {
        collider->SetStatic(false);
    }
}

Box::~Box() {
}

void Box::Update(float deltaTime) {
    UpdateComponents(deltaTime);
}
