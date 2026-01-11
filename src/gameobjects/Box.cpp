#include <gameobjects/Box.hpp>

Box::Box(std::string name, Scene* scene) : GameObject(name, scene)
{
    AddComponent(new Transform());
    AddComponent(new SpriteRenderer(
        static_cast<Transform &>(*GetComponentsByType("Transform")[0]), GetScene(), "../resources/textures/container.jpg"));
    AddComponent(new Collider(glm::vec2(0.0f, 0.0f), glm::vec2(32.0f, 32.0f)));
}

Box::~Box()
{
}

void Box::OnSetUp()
{
}

void Box::OnUpdate(float deltaTime)
{
}
