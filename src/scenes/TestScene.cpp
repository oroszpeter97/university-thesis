#include <scenes/TestScene.hpp>

#include <gameobjects/Player.hpp>

TestScene::TestScene() {
    SetUp();
}

TestScene::~TestScene() {
}

void TestScene::SetUp() {
    AddGameObject(new Player());
}
