#include <scenes/TestScene.hpp>

#include <gameobjects/Player.hpp>
#include <gameobjects/Box.hpp>

TestScene::TestScene() {
    SetUp();
}

TestScene::~TestScene() {
}

void TestScene::SetUp() {
    AddGameObject(new Player());
    AddGameObject(new Box());
}
