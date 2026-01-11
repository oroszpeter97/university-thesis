#pragma once

#include "core/Component.hpp"
#include <glm/glm.hpp>

class Collider : public Component
{
public:
    Collider();
    Collider(const glm::vec2 &position, const glm::vec2 &size);
    ~Collider();

    void OnSetUp() override;
    void OnUpdate(float deltaTime) override;
    virtual std::string GetType() const override;

    glm::vec2 GetPosition() const;
    glm::vec2 GetSize() const;
    void SetPosition(const glm::vec2 &newPosition);
    void SetSize(const glm::vec2 &newSize);
    void SetStatic(bool isStaticCollider);
    bool IsStatic() const;

private:
    glm::vec2 _position;
    glm::vec2 _size;
    bool _isStatic = false;

protected:
};