#include <scenes/TestScene.hpp>

#include <gameobjects/Player.hpp>
#include <gameobjects/Box.hpp>
#include <gameobjects/Box2.hpp>
#include <components/Transform.hpp>
#include <components/SpriteRenderer.hpp>
#include <gameobjects/Map.hpp>
#include <gameobjects/Camera.hpp>
#include <gameobjects/MapCollider.hpp>

#include <vector>

TestScene::TestScene(GLFWwindow* window) : Scene(window) {
    SetUp();
}

TestScene::~TestScene() {
}

void TestScene::SetUp() {
    // Map
    Map* map = new Map();
    Transform* mapTransform = nullptr;
    for (auto* comp : map->components) {
        mapTransform = dynamic_cast<Transform*>(comp);
        if (mapTransform) break;
    }
    if (mapTransform) {
        mapTransform->SetPosition(glm::vec3(0.0f, 0.0f, -10.0f));
        mapTransform->SetScale(glm::vec3(80.0f, 45.0f, 1.0f));
    }
    AddGameObject(map);

    // Player
    Player* player = new Player(inputManager);
    Transform* playerTransform = nullptr;
    for (auto* comp : player->components) {
        playerTransform = dynamic_cast<Transform*>(comp);
        if (playerTransform) break;
    }
    if (playerTransform) {
        playerTransform->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    }
    AddGameObject(player);

    // Moveable Box
    Box* box = new Box();
    Transform* boxTransform = nullptr;
    for (auto* comp : box->components) {
        boxTransform = dynamic_cast<Transform*>(comp);
        if (boxTransform) break;
    }
    if (boxTransform) {
        boxTransform->SetPosition(glm::vec3(640.0f, 360.0f, 0.0f));
    }
    AddGameObject(box);

    // Unmovable Box
    Box2* box2 = new Box2();
    Transform* box2Transform = nullptr;
    for (auto* comp : box2->components) {
        box2Transform = dynamic_cast<Transform*>(comp);
        if (box2Transform) break;
    }
    if (box2Transform) {
        box2Transform->SetPosition(glm::vec3(800.0f, 360.0f, 0.0f));
    }
    AddGameObject(box2);

    // Camera
    Camera* camera = new Camera(45.0f, 1280.0f / 720.0f, 0.1f, 100.0f, player, true);
    AddGameObject(camera);

    // Map Colliders 
    std::vector<MapCollider*> mapColliders;
    mapColliders.push_back(new MapCollider());
    for (int i = 0; i < mapColliders.size(); ++i) {
        Transform* transformComp = nullptr;
        Collider* colliderComp = nullptr;
        for (auto* comp : mapColliders[i]->components) {
            if (!transformComp) {
                transformComp = dynamic_cast<Transform*>(comp);
                if (transformComp) continue;
            }
            if (!colliderComp) {
                colliderComp = dynamic_cast<Collider*>(comp);
                if (colliderComp) continue;
            }
        }

        if (transformComp && colliderComp) {
            switch (i) {
                case 0:
                    transformComp->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
                    colliderComp->SetPosition(glm::vec2(0.0f, -24.0f));
                    colliderComp->SetSize(glm::vec2(576.0f, 320.0f));
                    break;
                default:
                    break;;
            }
        }
        AddGameObject(mapColliders[i]);
    }
}

void TestScene::UpdateGameObjects(float deltaTime) {
    Scene::UpdateGameObjects(deltaTime);

    // Collect all scene cameras
    std::vector<Camera*> cameras;
    for (auto& gameObject : gameObjects) {
        Camera* camera = dynamic_cast<Camera*>(gameObject);
        if (camera) {
            cameras.push_back(camera);
        }
    }

    // Get first active camera
    Camera *activeCamera = nullptr;
    if (!cameras.empty()) {
        for (auto& cam : cameras) {
            if (cam->IsActive()) {
                activeCamera = cam;
                break;
            }
        }
    }

    // Collect all SpriteRenderers and update them with the same camera view
    std::vector<SpriteRenderer*> spriteRenderers;
    for (auto& gameObject : gameObjects) {
        for (auto* comp : gameObject->components) {
            SpriteRenderer* spriteRenderer = dynamic_cast<SpriteRenderer*>(comp);
            if (spriteRenderer) {
                spriteRenderers.push_back(spriteRenderer);
            }
        }
    }

    for (auto& spriteRenderer : spriteRenderers) {
        if (activeCamera) {
            Transform* cameraTransform = nullptr;
            for (auto* comp : activeCamera->components) {
                cameraTransform = dynamic_cast<Transform*>(comp);
                if (cameraTransform) break;
            }
            if (cameraTransform) {
                spriteRenderer->UpdateViewPosition(glm::vec3(-cameraTransform->GetPosition().x, -cameraTransform->GetPosition().y, -20.0f));
            }
        }else{
            // Default view position if no active camera
            spriteRenderer->UpdateViewPosition(glm::vec3(0.0f, 0.0f, -20.0f));
        }
    }
}