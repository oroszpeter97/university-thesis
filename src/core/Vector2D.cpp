#include <core/Vector2D.hpp>
#include <cmath>

Vector2D::Vector2D() : X(0), Y(0)
{
}

Vector2D::Vector2D(float x, float y) : X(x), Y(y)
{
}

Vector2D Vector2D::operator+(const Vector2D &other) const
{
    return Vector2D(X + other.X, Y + other.Y);
}

Vector2D Vector2D::operator-(const Vector2D &other) const
{
    return Vector2D(X - other.X, Y - other.Y);
}

Vector2D Vector2D::operator*(float scalar) const
{
    return Vector2D(X * scalar, Y * scalar);
}

Vector2D Vector2D::operator*(const Vector2D &other) const
{
    return Vector2D(X * other.X, Y * other.Y);
}

Vector2D Vector2D::operator/(float scalar) const
{
    if (scalar == 0)
        return Vector2D(0, 0);
    return Vector2D(X / scalar, Y / scalar);
}

bool Vector2D::operator==(const Vector2D &other) const
{
    return X == other.X && Y == other.Y;
}

bool Vector2D::operator!=(const Vector2D &other) const
{
    return !(*this == other);
}

float Vector2D::Dot(const Vector2D &other) const
{
    return X * other.X + Y * other.Y;
}

float Vector2D::Length() const
{
    return std::sqrt(X * X + Y * Y);
}

Vector2D Vector2D::Normalize() const
{
    float length = Length();
    if (length == 0)
        return Vector2D(0, 0);
    return Vector2D(X / length, Y / length);
}

float Vector2D::DistanceTo(const Vector2D &other) const
{
    return (*this - other).Length();
}