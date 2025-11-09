#include <components/Script.hpp>
#include <iostream>

Script::Script(Transform& transform, InputManager& inputManager) : Component(), elapsedTime(0.0f), transform(transform), inputManager(inputManager) {

}

Script::~Script() {
    
}

void Script::Update(float deltaTime) {
    const float moveSpeed = 400.0f;
    const float rotateSpeed = 50.0f;
    if(inputManager.IsKeyPressed(GLFW_KEY_D)) {
        transform.SetPosition(transform.GetPosition() + glm::vec3(moveSpeed * deltaTime, 0.0f, 0.0f));
    }
    if(inputManager.IsKeyPressed(GLFW_KEY_A)) {
        transform.SetPosition(transform.GetPosition() + glm::vec3(-moveSpeed * deltaTime, 0.0f, 0.0f));
    }
    if(inputManager.IsKeyPressed(GLFW_KEY_W)) {
        transform.SetPosition(transform.GetPosition() + glm::vec3(0.0f, moveSpeed * deltaTime, 0.0f));
    }
    if(inputManager.IsKeyPressed(GLFW_KEY_S)) {
        transform.SetPosition(transform.GetPosition() + glm::vec3(0.0f, -moveSpeed * deltaTime, 0.0f));
    }
    if(inputManager.IsKeyPressed(GLFW_KEY_Q)) {
        transform.SetRotation(transform.GetRotation() + glm::vec3(0.0f, 0.0f, rotateSpeed * deltaTime));
    }
    if(inputManager.IsKeyPressed(GLFW_KEY_E)) {
        transform.SetRotation(transform.GetRotation() + glm::vec3(0.0f, 0.0f, -rotateSpeed * deltaTime));
    }
}