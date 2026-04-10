# Transform2D Documentation

## Overview

The `Transform2D` class represents the 2D spatial state of an object — its position, rotation, and scale. It provides operators for combining transforms and helper methods for directional queries and manipulation.

## Members

| Member     | Type       | Description                          |
|------------|------------|--------------------------------------|
| `Position` | `Vector2D` | World-space position                 |
| `Rotation` | `float`    | Rotation in degrees                  |
| `Scale`    | `Vector2D` | Scale factors along each axis        |

## Constructors

```cpp
Transform2D();  // Position (0,0), Rotation 0, Scale (1,1)
Transform2D(const Vector2D& position, float rotation, const Vector2D& scale);
```

## Operators

| Operator         | Description                                              |
|------------------|----------------------------------------------------------|
| `operator+(t)`   | Adds position, rotation, and scale of two transforms     |
| `operator-(t)`   | Subtracts position, rotation, and scale of two transforms|
| `operator==(t)`  | Equality comparison                                      |
| `operator!=(t)`  | Inequality comparison                                    |

## Methods

### `GetForward`
Returns the unit vector pointing in the direction of the current rotation.
```cpp
Vector2D forward = transform.GetForward();
```

### `GetRight`
Returns the unit vector pointing 90 degrees clockwise from the forward direction.
```cpp
Vector2D right = transform.GetRight();
```

### `LookAt`
Rotates the transform so that its forward direction points toward `target`.
```cpp
transform.LookAt(Vector2D(100.0f, 200.0f));
```

### `Rotate`
Adds `angle` degrees to the current rotation.
```cpp
transform.Rotate(45.0f);
```

### `Move`
Translates the position by `delta`.
```cpp
transform.Move(Vector2D(10.0f, 0.0f));
```

## Usage

```cpp
Transform2D t(Vector2D(0.0f, 0.0f), 0.0f, Vector2D(1.0f, 1.0f));

t.Move(Vector2D(5.0f, 3.0f));   // Position becomes (5, 3)
t.Rotate(90.0f);                 // Rotation becomes 90 degrees
t.LookAt(Vector2D(10.0f, 3.0f)); // Faces right

Vector2D fwd = t.GetForward();   // Direction the object is facing
Vector2D rgt = t.GetRight();     // Direction 90 degrees clockwise from forward
```

---
For more details, see the implementation in `src/core/Transform2D.cpp` and the header in `include/core/Transform2D.hpp`.
