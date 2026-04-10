#pragma once

class Vector2D
{
public:
    float X;
    float Y;

    Vector2D();
    Vector2D(float x, float y);

    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(float scalar) const;
    Vector2D operator*(const Vector2D& other) const;
    Vector2D operator/(float scalar) const;
    bool operator==(const Vector2D& other) const;
    bool operator!=(const Vector2D& other) const;
    float Dot(const Vector2D& other) const;
    float Length() const;
    Vector2D Normalize() const;
    float DistanceTo(const Vector2D& other) const;
};