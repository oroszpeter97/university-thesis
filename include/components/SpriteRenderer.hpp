#pragma once

#include <core/Component.hpp>
#include <core/Shader.hpp>
#include <components/Transform.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stb_image.h>

class SpriteRenderer : public Component {
public:
    SpriteRenderer(Transform& transform, const char* texturePath = "resources/textures/container.jpg");
    ~SpriteRenderer();

    void Update(float deltaTime) override;
    void UpdateViewPosition(const glm::vec3& newViewPosition) { viewPosition = newViewPosition; }

private:
    unsigned int texture1;
    Shader shader;
    unsigned int VAO;
    Transform& transform;
    glm::vec3 viewPosition;
};