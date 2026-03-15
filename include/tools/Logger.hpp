#pragma once

#include <mutex>
#include <string>
#include <memory>
#include <iostream>
#include <filesystem>
#include <fstream>		

enum class LogLevel
{
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Logger
{
public:
    ~Logger();

    static Logger &GetInstance();
    void Log(const std::string &message, LogLevel level = LogLevel::DEBUG);

private:
    static std::unique_ptr<Logger> _instance;
    static std::mutex _instanceMutex;

    LogLevel _logLevel = LogLevel::DEBUG;   // Default log level
    bool _logConsoleTarget = true;          // Log to console by default
    bool _logFileTarget = true;            // Log to file disabled by default
    std::string _logFileDirectory = "logs"; // Log file directory (if file logging is enabled)
    std::string _logFilePath;               // Path to the log file (if file logging is enabled)

    Logger();

    void LogToConsole(const std::string &message, LogLevel level);
    void LogToFile(const std::string &message, LogLevel level);
};