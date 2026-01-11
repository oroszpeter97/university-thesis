#include <core/Component.hpp>

Component::Component()
{
}

Component::~Component()
{
}

void Component::SetUp()
{
    OnSetUp();
}

void Component::Update(float deltaTime)
{
    OnUpdate(deltaTime);
}