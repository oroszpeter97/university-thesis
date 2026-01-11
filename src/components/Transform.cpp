#include <components/Transform.hpp>

Transform::Transform() : _position(0.0f), _rotation(0.0f), _scale(1.0f)
{
}

Transform::Transform(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale)
    : _position(position), _rotation(rotation), _scale(scale)
{
}

Transform::~Transform()
{
}

void Transform::OnSetUp()
{
}

void Transform::OnUpdate(float deltaTime)
{
}

std::string Transform::GetType() const
{
    return "Transform";
}

glm::vec3 Transform::GetPosition() const
{
    return _position;
}

glm::vec3 Transform::GetRotation() const
{
    return _rotation;
}

glm::vec3 Transform::GetScale() const
{
    return _scale;
}

void Transform::SetPosition(const glm::vec3 &newPosition)
{
    _position = newPosition;
}

void Transform::SetRotation(const glm::vec3 &newRotation)
{
    _rotation = newRotation;
}

void Transform::SetScale(const glm::vec3 &newScale)
{
    _scale = newScale;
}