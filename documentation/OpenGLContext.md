# OpenGLContext Documentation

## Overview

The `OpenGLContext` class encapsulates the initialization and lifecycle management of an OpenGL rendering context using GLFW and GLAD. It sets up a window, configures OpenGL state, and provides access to the underlying `GLFWwindow` handle.

## Features
- GLFW window creation with OpenGL 3.3 Core Profile
- Automatic GLAD loader initialization
- Default OpenGL state configuration (depth test, stencil test, face culling)
- Vertical image flip on load via stb_image
- Framebuffer resize callback registration
- Integrated logging via the `Logger` singleton

## OpenGL State Defaults
| Feature        | Setting              |
|----------------|----------------------|
| Depth test     | Enabled (`GL_LESS`)  |
| Stencil test   | Enabled              |
| Face culling   | Back-face (`GL_BACK`)|
| Image loading  | Flipped vertically   |

## Usage

### Creating a Context
```cpp
try {
    OpenGLContext context(1280, 720, "My Application");
    // guaranteed valid here
} catch (const std::runtime_error& e) {
    // initialization failed — message is in e.what() and the log
}
```

### Retrieving the Window Handle
```cpp
GLFWwindow* window = context.GetWindow();
```

### Example Main Loop
```cpp
OpenGLContext context(1280, 720, "My Application");
GLFWwindow* window = context.GetWindow();

while (!glfwWindowShouldClose(window)) {
    // render here
    glfwSwapBuffers(window);
    glfwPollEvents();
}
```

## Error Handling
Initialization errors are logged via `Logger` at `LogLevel::ERROR` and a `std::runtime_error` is thrown, so a failed construction never produces an invalid object.

| Failure                           | Exception message / Log            |
|-----------------------------------|------------------------------------|
| GLFW window creation failed       | `"Failed to create GLFW window"`   |
| GLAD loader initialization failed | `"Failed to initialize GLAD"`       |

No null-check on `GetWindow()` is needed; if the constructor returns normally, the context is fully valid.

## Lifecycle
The destructor automatically destroys the GLFW window (if created) and calls `glfwTerminate()`, so no manual cleanup is required.

```cpp
{
    OpenGLContext context(800, 600, "Window");
    // use context...
} // destructor cleans up GLFW here
```

## Framebuffer Resize
A static `FrameBufferSizeCallback` is registered automatically. It calls `glViewport` to update the viewport whenever the window is resized. No manual setup is needed.

---
For more details, see the implementation in `src/core/OpenGLContext.cpp` and the header in `include/core/OpenGLContext.hpp`.
