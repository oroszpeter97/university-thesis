#pragma once

#include "core/GameObject.hpp"
#include "core/Shader.hpp"

class Camera : public GameObject {
public:
    Camera(
        float fov, 
        float aspectRatio, 
        float nearClip, 
        float farClip, 
        GameObject* target = nullptr, 
        bool isActive = false,
        Shader shader = Shader("../shaders/default_vertex_shader.glsl", "../shaders/default_fragment_shader.glsl")
    );
    ~Camera();
    void Update(float deltaTime) override;
    void SetTarget(GameObject* target);
    bool IsActive() const { return isActive; }
private:
    float fov;
    float aspectRatio;
    float nearClip;
    float farClip;
    GameObject* target;
    Shader shader;
    bool isActive;
};