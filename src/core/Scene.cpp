#include <core/Scene.hpp>

Scene::Scene(GLFWwindow* window): inputManager(window), viewPosition(0.0f, 0.0f, -20.0f) {
    this->window = window;

}

Scene::~Scene() {
}

void Scene::AddGameObject(GameObject* gameObject) {
    gameObjects.push_back(gameObject);
}

void Scene::UpdateGameObjects(float deltaTime) {
    for (auto& gameObject : gameObjects) {
        gameObject->Update(deltaTime);
    }
    collisionManager.CheckCollisions(gameObjects, deltaTime);
}
