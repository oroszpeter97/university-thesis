# Logger Documentation

## Overview

The `Logger` class provides a simple and thread-safe logging utility for C++ projects. It supports logging messages to both the console and a file, with log levels and colored console output for better readability.

## Features
- Singleton pattern for global access
- Thread-safe logging
- Log levels: DEBUG, INFO, WARNING, ERROR
- Console output with color-coded log levels
- Optional file logging with automatic directory creation

## Log Levels and Colors
| Level   | Console Color |
|---------|--------------|
| DEBUG   | Cyan         |
| INFO    | Green        |
| WARNING | Yellow       |
| ERROR   | Red          |

## Usage

### Getting the Logger Instance
```cpp
Logger& logger = Logger::GetInstance();
```

### Logging a Message
```cpp
logger.Log("This is a debug message", LogLevel::DEBUG);
logger.Log("This is an info message", LogLevel::INFO);
logger.Log("This is a warning", LogLevel::WARNING);
logger.Log("This is an error", LogLevel::ERROR);
```

### Example Output
```
[DEBUG]   This is a debug message
[INFO]    This is an info message
[WARNING] This is a warning
[ERROR]   This is an error
```

Console output will be color-coded according to the log level.

## Configuration
- By default, both console and file logging are enabled.
- Log files are stored in the `logs/` directory with a timestamped filename.
- You can modify the logger's behavior by changing the relevant member variables in the `Logger` class.

## Thread Safety
The logger uses a mutex to ensure thread-safe access when logging from multiple threads.

## Extending
You can extend the logger to support additional log levels, output formats, or destinations as needed.

---
For more details, see the implementation in `src/tools/Logger.cpp` and the header in `include/tools/Logger.hpp`.
