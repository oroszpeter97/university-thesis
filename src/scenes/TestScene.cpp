#include <scenes/TestScene.hpp>

#include <gameobjects/Player.hpp>
#include <gameobjects/Box.hpp>
#include <gameobjects/Box2.hpp>
#include <components/Transform.hpp>
#include <components/SpriteRenderer.hpp>
#include <gameobjects/Map.hpp>

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
}

void TestScene::UpdateGameObjects(float deltaTime) {
    Scene::UpdateGameObjects(deltaTime);

    Player* player = nullptr;
    for (auto& gameObject : gameObjects) {
        player = dynamic_cast<Player*>(gameObject);
        if (player) break;
    }

    if (player) {
        Transform* playerTransform = nullptr;
        for (auto* comp : player->components) {
            playerTransform = dynamic_cast<Transform*>(comp);
            if (playerTransform) break;
        }
        if (playerTransform) {
            // Center camera on player (no per-sprite offset)
            setViewPosition(glm::vec3(
                -playerTransform->GetPosition().x,
                -playerTransform->GetPosition().y,
                -20.0f
            ));
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
        spriteRenderer->UpdateViewPosition(getViewPosition());
    }
}