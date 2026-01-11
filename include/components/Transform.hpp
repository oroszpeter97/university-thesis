#pragma once

#include <core/Component.hpp>
#include <glm/glm.hpp>

class Transform : public Component
{
public:
    Transform();
    Transform(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale);
    ~Transform();

    void OnSetUp() override;
    void OnUpdate(float deltaTime) override;
    virtual std::string GetType() const override;

    glm::vec3 GetPosition() const;
    glm::vec3 GetRotation() const;
    glm::vec3 GetScale() const;
    void SetPosition(const glm::vec3 &newPosition);
    void SetRotation(const glm::vec3 &newRotation);
    void SetScale(const glm::vec3 &newScale);

private:
    glm::vec3 _position;
    glm::vec3 _rotation;
    glm::vec3 _scale;

protected:
};