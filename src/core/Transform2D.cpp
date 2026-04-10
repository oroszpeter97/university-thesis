#include <core/Transform2D.hpp>

#include <cmath>

Transform2D::Transform2D() : Position(0, 0), Rotation(0), Scale(1, 1)
{
}

Transform2D::Transform2D(const Vector2D &position, float rotation, const Vector2D &scale)
    : Position(position), Rotation(rotation), Scale(scale)
{
}

Transform2D Transform2D::operator+(const Transform2D &other) const
{
    return Transform2D(Position + other.Position, Rotation + other.Rotation, Scale);
}

Transform2D Transform2D::operator-(const Transform2D &other) const
{
    return Transform2D(Position - other.Position, Rotation - other.Rotation, Scale);
}

bool Transform2D::operator==(const Transform2D &other) const
{
    return Position == other.Position && Rotation == other.Rotation && Scale == other.Scale;
}

bool Transform2D::operator!=(const Transform2D &other) const
{
    return !(*this == other);
}

Vector2D Transform2D::GetForward() const
{
    float radians = Rotation * (3.14159265f / 180.0f);
    return Vector2D(std::cos(radians), std::sin(radians));
}

Vector2D Transform2D::GetRight() const
{
    float radians = (Rotation + 90) * (3.14159265f / 180.0f);
    return Vector2D(std::cos(radians), std::sin(radians));
}

void Transform2D::LookAt(const Vector2D &target)
{
    Vector2D direction = target - Position;
    Rotation = std::atan2(direction.Y, direction.X) * (180.0f / 3.14159265f);
}

void Transform2D::Rotate(float angle)
{
    Rotation += angle;
}

void Transform2D::Move(const Vector2D &delta)
{
    Position = Position + delta;
}