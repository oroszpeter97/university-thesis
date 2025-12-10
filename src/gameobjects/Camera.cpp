#include "gameobjects/Camera.hpp"

#include "components/Transform.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Camera::Camera(float fov, float aspectRatio, float nearClip, float farClip, GameObject* target, bool isActive, Shader shader) : GameObject() {
    this->fov = fov;
    this->aspectRatio = aspectRatio;
    this->nearClip = nearClip;
    this->farClip = farClip;
    this->target = target;
    this->shader = shader;
    this->isActive = isActive;

    // Add a Transform component to the Camera
    AddComponent(new Transform());
}

Camera::~Camera() {}

void Camera::Update(float deltaTime) {
    // Get camera transform component
    Transform* cameraTransform = nullptr;
    for (Component* comp : components) {
        if(auto transformComp = dynamic_cast<Transform*>(comp)) {
            cameraTransform = transformComp;
            break;
        }
    }
    
    // Get target transform component
    Transform* targetTransform = nullptr;
    if(target != nullptr){
        for (Component* comp : target->GetComponents()) {
            if(auto transformComp = dynamic_cast<Transform*>(comp)) {
                targetTransform = transformComp;
                break;
            }
        }
    }

    if (cameraTransform && targetTransform) {
        Transform* cameraOffsetTransform = new Transform();
        cameraOffsetTransform->SetPosition(glm::vec3(targetTransform->GetPosition().x, targetTransform->GetPosition().y, -20.0f));
        // Simple follow logic: set camera position to target position
        cameraTransform->SetPosition(cameraOffsetTransform->GetPosition());
    }
}

void Camera::SetTarget(GameObject* target) {
    this->target = target;
}