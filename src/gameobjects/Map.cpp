#include <gameobjects/Map.hpp>

Map::Map(std::string name, Scene* scene) : GameObject(name, scene)
{
    AddComponent(new Transform());
    AddComponent(new SpriteRenderer(
        static_cast<Transform &>(*GetComponentsByType("Transform")[0]), GetScene(), "../resources/CastleMap.png"));
}

Map::~Map()
{
}

void Map::OnSetUp()
{
}

void Map::OnUpdate(float deltaTime)
{
}