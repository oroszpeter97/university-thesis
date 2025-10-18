cmake_minimum_required(VERSION 3.10)
project(university_thesis)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GLFW
add_subdirectory(external/glfw-3.4)

# Find OpenGL package
find_package(OpenGL REQUIRED)

# Include directories
include_directories(include)
include_directories(include/glad)
include_directories(include/KHR)
include_directories(include/core)
include_directories(include/components)
include_directories(include/gameobjects)
include_directories(include/scenes)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/core/OpenGLContext.cpp
    src/core/Component.cpp
    src/core/GameObject.cpp
    src/core/Scene.cpp
    src/core/InputManager.cpp
    src/components/Transform.cpp
    src/components/SpriteRenderer.cpp
    src/components/Script.cpp
    src/gameobjects/Player.cpp
    src/gameobjects/Box.cpp
    src/scenes/TestScene.cpp
    src/external/glad.c
    src/external/stb_image.cpp
)

# Link GLFW, OpenGL, and Assimp
target_link_libraries(university_thesis glfw OpenGL::GL)