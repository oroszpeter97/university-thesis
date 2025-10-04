#include <gameobjects/Box.hpp>

Box::Box() {
    AddComponent(new SpriteRenderer(glm::vec3(700.0f, 360.0f, 0.0f), glm::vec3(1.0f), 0.0f));
}

Box::~Box() {
}

void Box::Update(float deltaTime) {
    UpdateComponents(deltaTime);
}
