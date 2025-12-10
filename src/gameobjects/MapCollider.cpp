#include "gameobjects/MapCollider.hpp"

#include "components/Transform.hpp"
#include "components/SpriteRenderer.hpp"
#include "components/Collider.hpp"

MapCollider::MapCollider() : GameObject() {
    AddComponent(new Transform(glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
    AddComponent(new Collider(glm::vec2(0.0f, 0.0f), glm::vec2(32.0f, 32.0f)));

    Collider* collider = dynamic_cast<Collider*>(components[1]);
    if (collider) {
        collider->SetStatic(true);
    }
}

void MapCollider::Update(float deltaTime) {
    UpdateComponents(deltaTime);
}