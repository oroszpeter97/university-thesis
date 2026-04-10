# Vector2D Documentation

## Overview

The `Vector2D` class represents a 2D vector with `float` components. It provides common mathematical operations used in 2D graphics, physics, and geometry.

## Members

| Member | Type    | Description          |
|--------|---------|----------------------|
| `X`    | `float` | Horizontal component |
| `Y`    | `float` | Vertical component   |

## Constructors

```cpp
Vector2D();                    // Initializes X and Y to 0
Vector2D(float x, float y);   // Initializes with given components
```

## Operators

| Operator              | Description                                  |
|-----------------------|----------------------------------------------|
| `operator+(v)`        | Component-wise addition                      |
| `operator-(v)`        | Component-wise subtraction                   |
| `operator*(float)`    | Scalar multiplication                        |
| `operator*(v)`        | Component-wise multiplication (Hadamard)     |
| `operator/(float)`    | Scalar division                              |
| `operator==(v)`       | Equality comparison                          |
| `operator!=(v)`       | Inequality comparison                        |

## Methods

### `Dot`
Returns the dot product of this vector and `other`.
```cpp
float result = a.Dot(b);
```

### `Length`
Returns the Euclidean length (magnitude) of the vector.
```cpp
float len = v.Length();
```

### `Normalize`
Returns a unit vector in the same direction.
```cpp
Vector2D unit = v.Normalize();
```

### `DistanceTo`
Returns the Euclidean distance between this vector and `other`.
```cpp
float dist = a.DistanceTo(b);
```

## Usage

```cpp
Vector2D a(3.0f, 4.0f);
Vector2D b(1.0f, 2.0f);

Vector2D sum    = a + b;          // (4, 6)
float    dot    = a.Dot(b);       // 11
float    len    = a.Length();     // 5
Vector2D unit   = a.Normalize();  // (0.6, 0.8)
float    dist   = a.DistanceTo(b); // ~2.828
```

---
For more details, see the implementation in `src/core/Vector2D.cpp` and the header in `include/core/Vector2D.hpp`.
