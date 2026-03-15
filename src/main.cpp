#include <iostream>
#include <tools/Logger.hpp>

int main()
{
    Logger::GetInstance().Log("Application started", LogLevel::DEBUG);
    Logger::GetInstance().Log("This is an info message", LogLevel::INFO);
    Logger::GetInstance().Log("This is a warning message", LogLevel::WARNING);
    Logger::GetInstance().Log("This is an error message", LogLevel::ERROR);
    return 0;
}
