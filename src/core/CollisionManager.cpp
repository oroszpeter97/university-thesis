#include <core/CollisionManager.hpp>

CollisionManager::CollisionManager() {}
CollisionManager::~CollisionManager() {}

void CollisionManager::Update(std::vector<GameObject *> &gameObjects, float deltaTime)
{
    _time += deltaTime;
    // I don't even know what the f is going on here anymore...
    for (size_t i = 0; i < gameObjects.size(); ++i)
    {
        Collider *colliderA = gameObjects[i]->GetComponentsByType("Collider").empty()
                                  ? nullptr
                                  : dynamic_cast<Collider *>(gameObjects[i]->GetComponentsByType("Collider")[0]);
        Transform *transformA = gameObjects[i]->GetComponentsByType("Transform").empty()
                                   ? nullptr
                                   : dynamic_cast<Transform *>(gameObjects[i]->GetComponentsByType("Transform")[0]);
        if (!colliderA)
            continue;

        for (size_t j = i + 1; j < gameObjects.size(); ++j)
        {
            Collider *colliderB = gameObjects[j]->GetComponentsByType("Collider").empty()
                                      ? nullptr
                                      : dynamic_cast<Collider *>(gameObjects[j]->GetComponentsByType("Collider")[0]);
            Transform *transformB = gameObjects[j]->GetComponentsByType("Transform").empty()
                                       ? nullptr
                                       : dynamic_cast<Transform *>(gameObjects[j]->GetComponentsByType("Transform")[0]);
            if (!colliderB)
                continue;

            glm::vec2 posA = colliderA->GetPosition();
            glm::vec2 sizeA = colliderA->GetSize();
            glm::vec2 posB = colliderB->GetPosition();
            glm::vec2 sizeB = colliderB->GetSize();

            glm::vec2 transPosA(transformA->GetPosition().x, transformA->GetPosition().y);
            glm::vec2 transPosB(transformB->GetPosition().x, transformB->GetPosition().y);

            posA += transPosA;
            posB += transPosB;

            bool collisionX = posA.x + sizeA.x >= posB.x && posB.x + sizeB.x >= posA.x;
            bool collisionY = posA.y + sizeA.y >= posB.y && posB.y + sizeB.y >= posA.y;

            if (collisionX && collisionY)
            {
                /*std::cout << "Collision detected at time " << time
                          << " between GameObject at " << gameObjects[i]->GetClassName()
                          << " and GameObject " << gameObjects[j]->GetClassName() << std::endl;*/

                float overlapX = std::min(posA.x + sizeA.x, posB.x + sizeB.x) - std::max(posA.x, posB.x);
                float overlapY = std::min(posA.y + sizeA.y, posB.y + sizeB.y) - std::max(posA.y, posB.y);

                bool staticA = colliderA->IsStatic();
                bool staticB = colliderB->IsStatic();
                // std::cout << "Static A: " << staticA << ", Static B: " << staticB << std::endl;

                if (overlapX < overlapY)
                {
                    if (posA.x < posB.x)
                    {
                        if (!staticA && staticB)
                        {
                            glm::vec3 newPosA = transformA->GetPosition();
                            newPosA.x -= overlapX;
                            transformA->SetPosition(newPosA);
                        }
                        else if (staticA && !staticB)
                        {
                            glm::vec3 newPosB = transformB->GetPosition();
                            newPosB.x += overlapX;
                            transformB->SetPosition(newPosB);
                        }
                        else if (!staticA && !staticB)
                        {
                            float move = overlapX / 2.0f;
                            glm::vec3 newPosA = transformA->GetPosition();
                            glm::vec3 newPosB = transformB->GetPosition();
                            newPosA.x -= move;
                            newPosB.x += move;
                            transformA->SetPosition(newPosA);
                            transformB->SetPosition(newPosB);
                        }
                    }
                    else
                    {
                        if (!staticA && staticB)
                        {
                            glm::vec3 newPosA = transformA->GetPosition();
                            newPosA.x += overlapX;
                            transformA->SetPosition(newPosA);
                        }
                        else if (staticA && !staticB)
                        {
                            glm::vec3 newPosB = transformB->GetPosition();
                            newPosB.x -= overlapX;
                            transformB->SetPosition(newPosB);
                        }
                        else if (!staticA && !staticB)
                        {
                            float move = overlapX / 2.0f;
                            glm::vec3 newPosA = transformA->GetPosition();
                            glm::vec3 newPosB = transformB->GetPosition();
                            newPosA.x += move;
                            newPosB.x -= move;
                            transformA->SetPosition(newPosA);
                            transformB->SetPosition(newPosB);
                        }
                    }
                }
                else
                {
                    if (posA.y < posB.y)
                    {
                        if (!staticA && staticB)
                        {
                            glm::vec3 newPosA = transformA->GetPosition();
                            newPosA.y -= overlapY;
                            transformA->SetPosition(newPosA);
                        }
                        else if (staticA && !staticB)
                        {
                            glm::vec3 newPosB = transformB->GetPosition();
                            newPosB.y += overlapY;
                            transformB->SetPosition(newPosB);
                        }
                        else if (!staticA && !staticB)
                        {
                            float move = overlapY / 2.0f;
                            glm::vec3 newPosA = transformA->GetPosition();
                            glm::vec3 newPosB = transformB->GetPosition();
                            newPosA.y -= move;
                            newPosB.y += move;
                            transformA->SetPosition(newPosA);
                            transformB->SetPosition(newPosB);
                        }
                    }
                    else
                    {
                        if (!staticA && staticB)
                        {
                            glm::vec3 newPosA = transformA->GetPosition();
                            newPosA.y += overlapY;
                            transformA->SetPosition(newPosA);
                        }
                        else if (staticA && !staticB)
                        {
                            glm::vec3 newPosB = transformB->GetPosition();
                            newPosB.y -= overlapY;
                            transformB->SetPosition(newPosB);
                        }
                        else if (!staticA && !staticB)
                        {
                            float move = overlapY / 2.0f;
                            glm::vec3 newPosA = transformA->GetPosition();
                            glm::vec3 newPosB = transformB->GetPosition();
                            newPosA.y += move;
                            newPosB.y -= move;
                            transformA->SetPosition(newPosA);
                            transformB->SetPosition(newPosB);
                        }
                    }
                }
            }
        }
    }
}