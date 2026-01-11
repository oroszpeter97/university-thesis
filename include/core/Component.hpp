#pragma once

#include <string>

class Component
{
public:
    Component();
    ~Component();

    void SetUp();
    void Update(float deltaTime);

    virtual std::string GetType() const = 0;

private:

protected:
    virtual void OnSetUp() = 0;
    virtual void OnUpdate(float deltaTime) = 0;
};