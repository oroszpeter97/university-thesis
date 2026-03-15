#include <tools/Logger.hpp>

int main()
{
    Logger& logger = Logger::GetInstance();

    logger.Log("Application started", LogLevel::DEBUG);
    logger.Log("This is an info message", LogLevel::INFO);
    logger.Log("This is a warning message", LogLevel::WARNING);
    logger.Log("This is an error message", LogLevel::ERROR);
    return 0;
}
