#include <gameobjects/Map.hpp>

Map::Map() {
    AddComponent(new Transform());
    AddComponent(new SpriteRenderer(static_cast<Transform&>(*components[0]), "../resources/CastleMap.png"));
}

Map::~Map() {
}

void Map::Update(float deltaTime) {
    UpdateComponents(deltaTime);
}
