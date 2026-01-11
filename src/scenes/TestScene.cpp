#include <scenes/TestScene.hpp>

#include <gameobjects/Player.hpp>
#include <gameobjects/Box.hpp>
#include <components/Transform.hpp>
#include <components/SpriteRenderer.hpp>
#include <gameobjects/Map.hpp>
#include <gameobjects/Camera.hpp>

#include <vector>

TestScene::TestScene(GLFWwindow *window) : Scene(window)
{
}

TestScene::~TestScene()
{
}

void TestScene::OnSetUp()
{
    std::cout << "Setting up TestScene." << std::endl;
    // Map
    std::cout << "Adding Map to TestScene." << std::endl;
    Map *map = new Map("Map", this);
    std::cout << "Getting Map Transform." << std::endl;
    Transform *mapTransform = map->GetComponentsByType("Transform").empty()
                                  ? nullptr
                                  : dynamic_cast<Transform *>(map->GetComponentsByType("Transform")[0]);
    std::cout << "Setting Map Transform properties." << std::endl;
    if (mapTransform)
    {
        mapTransform->SetPosition(glm::vec3(0.0f, 0.0f, -10.0f));
        mapTransform->SetScale(glm::vec3(80.0f, 45.0f, 1.0f));
    }
    std::cout << "Adding Map to Scene." << std::endl;
    AddGameObject(map);

    // Player
    Player *player = new Player("Player", this, GetInputManager());
    Transform *playerTransform = player->GetComponentsByType("Transform").empty()
                                     ? nullptr
                                     : dynamic_cast<Transform *>(player->GetComponentsByType("Transform")[0]);
    if (playerTransform)
    {
        playerTransform->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    }
    AddGameObject(player);

    // Moveable Box
    Box *box1 = new Box("Box1", this);
    Transform *box1Transform = box1->GetComponentsByType("Transform").empty()
                                  ? nullptr
                                  : dynamic_cast<Transform *>(box1->GetComponentsByType("Transform")[0]);
    Collider *box1Collider = box1->GetComponentsByType("Collider").empty()
                                  ? nullptr
                                  : dynamic_cast<Collider *>(box1->GetComponentsByType("Collider")[0]);
    if (box1Transform)
    {
        box1Transform->SetPosition(glm::vec3(640.0f, 360.0f, 0.0f));
    }
    if (box1Collider)
    {
        box1Collider->SetStatic(false);
    }
    AddGameObject(box1);

    // Unmovable Box
    Box *box2 = new Box("Box2", this);
    Transform *box2Transform = box2->GetComponentsByType("Transform").empty()
                                  ? nullptr
                                  : dynamic_cast<Transform *>(box2->GetComponentsByType("Transform")[0]);
    Collider *box2Collider = box2->GetComponentsByType("Collider").empty()
                                  ? nullptr
                                  : dynamic_cast<Collider *>(box2->GetComponentsByType("Collider")[0]);
    if (box2Transform)
    {
        box2Transform->SetPosition(glm::vec3(800.0f, 360.0f, 0.0f));
    }
    if (box2Collider)
    {
        box2Collider->SetStatic(true);
    }
    AddGameObject(box2);

    // Camera
    Camera *camera = new Camera(45.0f, 1280.0f / 720.0f, 0.1f, 100.0f, "Camera", this, player, true);
    AddGameObject(camera);
}

void TestScene::OnUpdate(float deltaTime)
{
    // Collect all scene cameras
    std::vector<GameObject *> cameras = GetGameObjectsByType("Camera");

    // Get first active camera
    if (!cameras.empty())
    {
        for (auto &cam : cameras)
        {
            if (static_cast<Camera *>(cam)->IsActive())
            {
                SetActiveCamera(static_cast<Camera *>(cam));
                break;
            }
        }
    }
}