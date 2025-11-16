#include <scenes/TestScene.hpp>

#include <gameobjects/Player.hpp>
#include <gameobjects/Box.hpp>
#include <gameobjects/Box2.hpp>

TestScene::TestScene(GLFWwindow* window) : Scene(window) {
    SetUp();
}

TestScene::~TestScene() {
}

void TestScene::SetUp() {
    AddGameObject(new Player(inputManager));

    // Manually set box 1 position
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

    // Manually set box 2 position
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