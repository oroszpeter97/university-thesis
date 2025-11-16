#include <gameobjects/Box.hpp>

Box::Box() {
    AddComponent(new Transform());
    AddComponent(new SpriteRenderer(static_cast<Transform&>(*components[0])));
    AddComponent(new Collider(glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f)));
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
