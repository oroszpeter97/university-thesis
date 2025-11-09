#pragma once

#include "core/Component.hpp"
#include <glm/glm.hpp>

class Collider : public Component {
public:
    Collider();
    Collider(const glm::vec2& position, const glm::vec2& size);
    ~Collider();

    void Update(float deltaTime) override {}
    
    glm::vec2 GetPosition() const { return position; }
    glm::vec2 GetSize() const { return size; }
    void SetPosition(const glm::vec2& newPosition) { position = newPosition; }
    void SetSize(const glm::vec2& newSize) { size = newSize; }

private:
    glm::vec2 position;
    glm::vec2 size;
};