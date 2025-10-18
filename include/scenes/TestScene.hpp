#pragma once

#include <core/Scene.hpp>

class TestScene : public Scene {
public:
    TestScene(GLFWwindow* window);
    ~TestScene();

    void SetUp() override;

private:
    
};
