#include <scenes/TestScene.hpp>

#include <gameobjects/Player.hpp>
#include <gameobjects/Box.hpp>

TestScene::TestScene(GLFWwindow* window) : Scene(window) {
    SetUp();
}

TestScene::~TestScene() {
}

void TestScene::SetUp() {
    AddGameObject(new Player(inputManager));
    AddGameObject(new Box());
}
