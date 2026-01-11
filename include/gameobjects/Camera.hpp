#pragma once

#include "core/GameObject.hpp"
#include "core/Shader.hpp"

class Camera : public GameObject
{
public:
    Camera(
        float fov,
        float aspectRatio,
        float nearClip,
        float farClip,
        std::string name,
        Scene* scene,
        GameObject *target = nullptr,
        bool isActive = false,
        Shader shader = Shader("../shaders/default_vertex_shader.glsl", "../shaders/default_fragment_shader.glsl"));
    ~Camera();

    void OnSetUp() override;
    void OnUpdate(float deltaTime) override;
    float GetFov() const;
    void SetFov(float fov);
    float GetAspectRatio() const;
    void SetAspectRatio(float aspectRatio);
    float GetNearClip() const;
    void SetNearClip(float nearClip);
    float GetFarClip() const;
    void SetFarClip(float farClip);
    GameObject *GetTarget() const;
    void SetTarget(GameObject *target);
    Shader GetShader() const;
    void SetShader(const Shader shader);
    bool IsActive() const;
    void SetActive(bool isActive);

private:
    float _fov;
    float _aspectRatio;
    float _nearClip;
    float _farClip;
    GameObject *_target;
    Shader _shader;
    bool _isActive;

protected:
};