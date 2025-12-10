#include <components/Transform.hpp>

Transform::Transform(): position(0.0f), rotation(0.0f), scale(1.0f) {
}

Transform::Transform(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale)
    : position(position), rotation(rotation), scale(scale) {
}

Transform::~Transform() {
}

void Transform::Update(float deltaTime) {
}
