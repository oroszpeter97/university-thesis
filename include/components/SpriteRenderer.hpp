#pragma once

#include <core/Component.hpp>
#include <core/Shader.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stb_image.h>

class SpriteRenderer : public Component {
public:
    SpriteRenderer(glm::vec3 position = glm::vec3(0.0f), glm::vec3 size = glm::vec3(1.0f), float rotation = 0.0f);
    ~SpriteRenderer();

    void Update(float deltaTime) override;

private:
    glm::vec3 position;
    glm::vec3 size;
    float rotation;
    unsigned int texture1;
    Shader shader;
    unsigned int VAO;
};