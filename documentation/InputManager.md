
# InputManager Documentation

## Overview

The `InputManager` class provides a unified interface for handling keyboard and mouse input in C++ applications using GLFW. It abstracts key and mouse button codes, supports querying input states, and manages the window context for input polling.

## Features
- Singleton pattern for global access (thread-safe initialization)
- Abstraction over GLFW key and mouse button codes
- Query key and mouse button states (pressed/released)
- Retrieve current mouse cursor position
- Easy window context management
- Integrated logging via the `Logger` class

## Usage

### Getting the InputManager Instance
```cpp
InputManager& input = InputManager::GetInstance();
```

### Setting the Window Context
```cpp
GLFWwindow* window = /* ... */;
input.SetWindowContext(window);
```

### Querying Key and Mouse States
```cpp
if (input.IsKeyPressed(Input::Keys::A)) {
	// Handle 'A' key pressed
}

if (input.IsMouseButtonPressed(Input::MouseButtons::Left)) {
	// Handle left mouse button pressed
}

if (input.IsKeyReleased(Input::Keys::Escape)) {
	// Handle Escape key released
}
```


### Getting Mouse Position (Screen Space)
```cpp
MousePosition pos = input.GetMousePosition();
std::cout << "Mouse X: " << pos.x << ", Y: " << pos.y << std::endl;
```
The returned mouse position is in screen space coordinates relative to the top-left corner of the window (as per GLFW's convention).

## Supported Keys and Mouse Buttons

See `Input::Keys` and `Input::MouseButtons` enums in `include/core/InputManager.hpp` for all supported values (A-Z, 0-9, F1-F12, arrows, modifiers, etc.).

## Configuration
- The window context must be set via `SetWindowContext()` before querying input states.
- Uses the `Logger` singleton for internal logging (see Logger documentation for details).

## Thread Safety
The singleton instance is created using a function-local static in `GetInstance()`, which is thread-safe since C++11. Input queries are not inherently thread-safe; ensure input polling occurs on the main thread as required by GLFW.

## Extending
You can extend the `InputManager` to support additional keys, mouse buttons, or input devices by modifying the enums and internal maps. Additional input features (e.g., scroll, gamepad) can be added as needed.

---
For more details, see the implementation in `src/core/InputManager.cpp` and the header in `include/core/InputManager.hpp`.
