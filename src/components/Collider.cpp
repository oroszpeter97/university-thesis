#include "components/Collider.hpp"

Collider::Collider(const glm::vec2& position, const glm::vec2& size)
    : position(position), size(size) {}

Collider::Collider() : position(0.0f, 0.0f), size(1.0f, 1.0f) {}

Collider::~Collider() {}