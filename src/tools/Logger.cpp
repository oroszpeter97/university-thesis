#include "tools/Logger.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>		
#include <ctime>

namespace
{
	std::mutex logMutex;
}

Logger::Logger()
{
	if (_logFileTarget)
	{
		std::filesystem::path logDir(_logFileDirectory);
 		std::error_code ec;
 		std::filesystem::create_directories(logDir, ec);
		if (ec)
 		{
 			_logFileTarget = false;
 			_logFilePath.clear();
 			return;
 		}
		
		std::time_t t = std::time(nullptr);
		std::tm tm{};
		bool timeOk = true;
#ifdef _WIN32
		timeOk = (localtime_s(&tm, &t) == 0);
#else
		timeOk = (localtime_r(&t, &tm) != nullptr);
#endif
		if (!timeOk)
		{
			_logFileTarget = false;
			_logFilePath.clear();
			return;
		}
		char buf[32];
		std::strftime(buf, sizeof(buf), "%Y-%m-%d-%H-%M-%S", &tm);
		std::string logFileName = std::string("log") + buf + ".log";
 		std::filesystem::path logFilePath = logDir / logFileName;
 		_logFilePath = logFilePath.string();
	}
}

Logger::~Logger()
{
	
}

Logger &Logger::GetInstance()
{
	static Logger instance;
 	return instance;
}

void Logger::Log(const std::string &message, LogLevel level)
{
	std::lock_guard<std::mutex> lock(logMutex);

	if (level < _logLevel)
	{
		return;
	}

	if (_logConsoleTarget)
	{
		LogToConsole(message, level);
	}

	if (_logFileTarget)
	{
		LogToFile(message, level);
	}
}

void Logger::LogToConsole(const std::string &message, LogLevel level)
{
	std::string levelStr;
	std::string colorCode;
	std::string resetCode;

#ifdef _WIN32
	// Disable ANSI color codes on Windows by default to avoid raw escape sequences
	resetCode.clear();
#else
	resetCode = "\033[0m";
#endif

	switch (level)
	{
	case LogLevel::DEBUG:
		levelStr = "DEBUG";
#ifndef _WIN32
		colorCode = "\033[36m"; // Cyan
#endif
		break;
	case LogLevel::INFO:
		levelStr = "INFO";
#ifndef _WIN32
		colorCode = "\033[32m"; // Green
#endif
		break;
	case LogLevel::WARNING:
		levelStr = "WARNING";
#ifndef _WIN32
		colorCode = "\033[33m"; // Yellow
#endif
		break;
	case LogLevel::ERROR:
		levelStr = "ERROR";
#ifndef _WIN32
		colorCode = "\033[31m"; // Red
#endif
		break;
	default:
 		levelStr = "UNKNOWN";
 		colorCode = resetCode;
 		break;
 	}
	std::cout << colorCode << "[" << levelStr << "] " << message << resetCode << '\n';
}

void Logger::LogToFile(const std::string &message, LogLevel level)
{
	if (_logFilePath.empty())
		return;
	std::ofstream file(_logFilePath, std::ios::app);
	if (!file.is_open())
		return;
	std::string levelStr;
	switch (level)
	{
	case LogLevel::DEBUG:
		levelStr = "DEBUG";
		break;
	case LogLevel::INFO:
		levelStr = "INFO";
		break;
	case LogLevel::WARNING:
		levelStr = "WARNING";
		break;
	case LogLevel::ERROR:
		levelStr = "ERROR";
		break;
	default:
 		levelStr = "UNKNOWN";
 		break;
	}
	file << "[" << levelStr << "] " << message << '\n';
}
