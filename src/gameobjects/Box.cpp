#include <gameobjects/Box.hpp>

Box::Box() {
    AddComponent(new Transform());
    AddComponent(new SpriteRenderer(static_cast<Transform&>(*components[0])));
}

Box::~Box() {
}

void Box::Update(float deltaTime) {
    UpdateComponents(deltaTime);
}
