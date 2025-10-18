#pragma once

#include <core/Component.hpp>
#include <glm/glm.hpp>

class Transform : public Component {
public:
    Transform();
    ~Transform();

    void Update(float deltaTime) override;
    glm::vec3 GetPosition() const { return position; }
    glm::vec3 GetRotation() const { return rotation; }
    glm::vec3 GetScale() const { return scale; }
    void SetPosition(const glm::vec3& newPosition) { position = newPosition; }
    void SetRotation(const glm::vec3& newRotation) { rotation = newRotation; }
    void SetScale(const glm::vec3& newScale) { scale = newScale; }

private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};