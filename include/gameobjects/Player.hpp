#pragma once

#include <core/GameObject.hpp>
#include <components/Transform.hpp>

class Player : public GameObject {
public:
    Player();
    ~Player();

    void Update(float deltaTime) override;

private:

};
