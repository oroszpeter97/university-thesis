#include <components/Script.hpp>
#include <iostream>

Script::Script(Transform& transform, InputManager& inputManager) : Component(), elapsedTime(0.0f), transform(transform), inputManager(inputManager) {

}

Script::~Script() {
    
}

void Script::Update(float deltaTime) {
    if(inputManager.IsKeyPressed(GLFW_KEY_D)) {
        transform.SetPosition(transform.GetPosition() + glm::vec3(5.0f, 0.0f, 0.0f));
    }
    if(inputManager.IsKeyPressed(GLFW_KEY_A)) {
        transform.SetPosition(transform.GetPosition() + glm::vec3(-5.0f, 0.0f, 0.0f));
    }
    if(inputManager.IsKeyPressed(GLFW_KEY_W)) {
        transform.SetPosition(transform.GetPosition() + glm::vec3(0.0f, 5.0f, 0.0f));
    }
    if(inputManager.IsKeyPressed(GLFW_KEY_S)) {
        transform.SetPosition(transform.GetPosition() + glm::vec3(0.0f, -5.0f, 0.0f));
    }
    if(inputManager.IsKeyPressed(GLFW_KEY_Q)) {
        transform.SetRotation(transform.GetRotation() + glm::vec3(0.0f, 0.0f, 2.0f));
    }
    if(inputManager.IsKeyPressed(GLFW_KEY_E)) {
        transform.SetRotation(transform.GetRotation() + glm::vec3(0.0f, 0.0f, -2.0f));
    }
}