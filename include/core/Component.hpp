#pragma once

#include <iostream>

class Component {
public:
    /**
     * @brief Constructs a new Component object.
     */
    Component();
    /**
     * @brief Destroys the Component object.
     */
    ~Component();
    /**
     * @brief Runs every frame to update the Component.
     * @param deltaTime The time elapsed since the last update.
     */
    virtual void Update(float deltaTime) = 0;

private:

};