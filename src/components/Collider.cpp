#include "components/Collider.hpp"

Collider::Collider(const glm::vec2 &position, const glm::vec2 &size) : _position(position), _size(size)
{
}

Collider::Collider() : _position(0.0f, 0.0f), _size(1.0f, 1.0f)
{
}

Collider::~Collider()
{
}

void Collider::OnSetUp()
{
}

void Collider::OnUpdate(float deltaTime)
{
}

std::string Collider::GetType() const
{
    return "Collider";
}

glm::vec2 Collider::GetPosition() const
{
    return _position;
}

glm::vec2 Collider::GetSize() const
{
    return _size;
}

void Collider::SetPosition(const glm::vec2 &newPosition)
{
    _position = newPosition;
}

void Collider::SetSize(const glm::vec2 &newSize)
{
    _size = newSize;
}

void Collider::SetStatic(bool isStaticCollider)
{
    _isStatic = isStaticCollider;
}

bool Collider::IsStatic() const
{
    return _isStatic;
}