#pragma once

#include <core/Vector2D.hpp>

class Transform2D
{
public:
    Vector2D Position;
    float Rotation;     // In degrees
    Vector2D Scale;

    Transform2D();
    Transform2D(const Vector2D& position, float rotation, const Vector2D& scale);

    Transform2D operator+(const Transform2D& other) const;
    Transform2D operator-(const Transform2D& other) const;
    bool operator==(const Transform2D& other) const;
    bool operator!=(const Transform2D& other) const;

    Vector2D GetForward() const;
    Vector2D GetRight() const;

    void LookAt(const Vector2D& target);
    void Rotate(float angle);
    void Move(const Vector2D& delta);
};