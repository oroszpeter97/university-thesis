#pragma once

#include <core/Component.hpp>
#include <core/Shader.hpp>
#include <components/Transform.hpp>
#include <core/Scene.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stb_image.h>

class SpriteRenderer : public Component
{
public:
    SpriteRenderer(Transform &transform, Scene *scene, const char *texturePath = "resources/textures/container.jpg");
    ~SpriteRenderer();

    void OnSetUp() override;
    void OnUpdate(float deltaTime) override;
    virtual std::string GetType() const override;

private:
    unsigned int _texture1;
    Shader _shader;
    unsigned int _VAO;
    Transform &_transform;
    Scene *_scene;

protected:
};