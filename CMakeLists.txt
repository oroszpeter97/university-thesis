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

add_executable(${PROJECT_NAME} src/main.cpp src/core/OpenGLContext.cpp src/external/glad.c src/external/stb_image.cpp)

# Link GLFW, OpenGL, and Assimp
target_link_libraries(university_thesis glfw OpenGL::GL)