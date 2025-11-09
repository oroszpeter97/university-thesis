#include <core/CollisionManager.hpp>

CollisionManager::CollisionManager() {}
CollisionManager::~CollisionManager() {}

void CollisionManager::CheckCollisions(std::vector<GameObject*>& gameObjects, float deltaTime) {
    time += deltaTime;
    for (size_t i = 0; i < gameObjects.size(); ++i) {
        Collider* colliderA = nullptr;
        Transform* transformA = nullptr;
        for (auto& comp : gameObjects[i]->GetComponents()) {
            if (!colliderA)
                colliderA = dynamic_cast<Collider*>(comp);
            if (!transformA)
                transformA = dynamic_cast<Transform*>(comp);
            if (colliderA && transformA) break;
        }
        if (!colliderA) continue;

        for (size_t j = i + 1; j < gameObjects.size(); ++j) {
            Collider* colliderB = nullptr;
            Transform* transformB = nullptr;
            for (auto& comp : gameObjects[j]->GetComponents()) {
                if (!colliderB)
                    colliderB = dynamic_cast<Collider*>(comp);
                if (!transformB)
                    transformB = dynamic_cast<Transform*>(comp);
                if (colliderB && transformB) break;
            }
            if (!colliderB) continue;

            glm::vec2 posA = colliderA->GetPosition();
            glm::vec2 sizeA = colliderA->GetSize();
            glm::vec2 posB = colliderB->GetPosition();
            glm::vec2 sizeB = colliderB->GetSize();

            posA += glm::vec2(transformA->GetPosition().x, transformA->GetPosition().y);
            posB += glm::vec2(transformB->GetPosition().x, transformB->GetPosition().y);

            bool collisionX = posA.x + sizeA.x >= posB.x && posB.x + sizeB.x >= posA.x;
            bool collisionY = posA.y + sizeA.y >= posB.y && posB.y + sizeB.y >= posA.y;

            if (collisionX && collisionY) {
                std::cout << "Collision detected at time " << time
                          << " between GameObject at " << gameObjects[i]->GetClassName()
                          << " and GameObject " << gameObjects[j]->GetClassName() << std::endl;
            }
        }
    }
}