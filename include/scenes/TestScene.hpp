#pragma once

#include <core/Scene.hpp>

class TestScene : public Scene
{
public:
    TestScene(GLFWwindow *window);
    ~TestScene();

    void OnSetUp() override;
    void OnUpdate(float deltaTime) override;

private:
protected:
};
