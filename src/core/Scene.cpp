#include <core/Scene.hpp>

Scene::Scene(GLFWwindow* window): inputManager(window) {

}

Scene::~Scene() {
}

void Scene::AddGameObject(GameObject* gameObject) {
    gameObjects.push_back(gameObject);
}

void Scene::RemoveGameObject(GameObject* gameObject) {
    gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gameObject), gameObjects.end());
}

void Scene::UpdateGameObjects(float deltaTime) {
    for (auto& gameObject : gameObjects) {
        gameObject->Update(deltaTime);
    }
}
