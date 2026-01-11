#include "gameobjects/Camera.hpp"

#include "components/Transform.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Camera::Camera(
    float fov,
    float aspectRatio,
    float nearClip,
    float farClip,
    std::string name,
    Scene* scene,
    GameObject *target,
    bool isActive,
    Shader shader) : GameObject(name, scene)
{
    _fov = fov;
    _aspectRatio = aspectRatio;
    _nearClip = nearClip;
    _farClip = farClip;
    _target = target;
    _isActive = isActive;
    _shader = shader;

    AddComponent(new Transform());
}

Camera::~Camera() {}

void Camera::OnSetUp()
{
}

void Camera::OnUpdate(float deltaTime)
{
    Transform *cameraTransform = GetComponentsByType("Transform").empty()
                                     ? nullptr
                                     : dynamic_cast<Transform *>(GetComponentsByType("Transform")[0]);

    Transform *targetTransform = _target == nullptr
                                     ? nullptr
                                 : _target->GetComponentsByType("Transform").empty()
                                     ? nullptr
                                     : dynamic_cast<Transform *>(_target->GetComponentsByType("Transform")[0]);

    if (cameraTransform && targetTransform)
    {
        Transform *cameraOffsetTransform = new Transform();
        cameraOffsetTransform->SetPosition(glm::vec3(targetTransform->GetPosition().x, targetTransform->GetPosition().y, -20.0f));
        // Simple follow logic: set camera position to target position
        cameraTransform->SetPosition(cameraOffsetTransform->GetPosition());
    }
}

float Camera::GetFov() const
{
    return _fov;
}

void Camera::SetFov(float fov)
{
    _fov = fov;
}

float Camera::GetAspectRatio() const
{
    return _aspectRatio;
}

void Camera::SetAspectRatio(float aspectRatio)
{
    _aspectRatio = aspectRatio;
}

float Camera::GetNearClip() const
{
    return _nearClip;
}

void Camera::SetNearClip(float nearClip)
{
    _nearClip = nearClip;
}

float Camera::GetFarClip() const
{
    return _farClip;
}

void Camera::SetFarClip(float farClip)
{
    _farClip = farClip;
}

GameObject *Camera::GetTarget() const
{
    return _target;
}

void Camera::SetTarget(GameObject *target)
{
    _target = target;
}

Shader Camera::GetShader() const
{
    return _shader;
}

void Camera::SetShader(const Shader shader)
{
    _shader = shader;
}

bool Camera::IsActive() const
{
    return _isActive;
}

void Camera::SetActive(bool isActive)
{
    _isActive = isActive;
}