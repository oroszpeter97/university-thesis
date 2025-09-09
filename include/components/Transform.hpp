#pragma once

#include <core/Component.hpp>

class Transform : public Component {
public:
    Transform();
    ~Transform();

    void Update(float deltaTime) override;

private:

};