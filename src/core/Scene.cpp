#include <core/Scene.hpp>

Scene::Scene(GLFWwindow *window) : _window(window), _inputManager(window)
{
}

Scene::~Scene()
{
}

void Scene::SetUp()
{
    std::cout << "Setting up Scene." << std::endl;
    OnSetUp();
}

void Scene::Update(float deltaTime)
{
    for (auto &gameObject : _gameObjects)
    {
        gameObject->Update(deltaTime);
    }

    _collisionManager.Update(_gameObjects, deltaTime);

    OnUpdate(deltaTime);
}

void Scene::AddGameObject(GameObject *gameObject)
{
    gameObject->SetUp();
    _gameObjects.push_back(gameObject);
}

Camera *Scene::GetActiveCamera()
{
    return _activeCamera;
}

void Scene::SetActiveCamera(Camera *camera)
{
    _activeCamera = camera;
}

GLFWwindow *Scene::GetWindow()
{
    return _window;
}

std::vector<GameObject *> &Scene::GetGameObjects()
{
    return _gameObjects;
}

InputManager &Scene::GetInputManager()
{
    return _inputManager;
}

CollisionManager &Scene::GetCollisionManager()
{
    return _collisionManager;
}

std::vector<GameObject *> Scene::GetGameObjectsByName(const std::string &name)
{
    std::vector<GameObject *> result;
    for (auto &gameObject : _gameObjects)
    {
        if (gameObject->GetName() == name)
        {
            result.push_back(gameObject);
        }
    }
    return result;
}

std::vector<GameObject *> Scene::GetGameObjectsByType(const std::string &type)
{
    std::vector<GameObject *> result;
    for (auto &gameObject : _gameObjects)
    {
        if (gameObject->GetClassName() == type)
        {
            result.push_back(gameObject);
        }
    }
    return result;
}