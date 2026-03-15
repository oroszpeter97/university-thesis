#include "tools/Logger.hpp"

std::unique_ptr<Logger> Logger::_instance = nullptr;
std::mutex Logger::_instanceMutex;

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
		
		std::time_t t = std::time(nullptr);
		std::tm tm;
#ifdef _WIN32
		localtime_s(&tm, &t);
#else
		localtime_r(&t, &tm);
#endif
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
	std::lock_guard<std::mutex> lock(_instanceMutex);
	if (!_instance)
	{
		_instance.reset(new Logger());
	}
	return *_instance;
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
	std::string resetCode = "\033[0m";
	switch (level)
	{
	case LogLevel::DEBUG:
		levelStr = "DEBUG";
		colorCode = "\033[36m"; // Cyan
		break;
	case LogLevel::INFO:
		levelStr = "INFO";
		colorCode = "\033[32m"; // Green
		break;
	case LogLevel::WARNING:
		levelStr = "WARNING";
		colorCode = "\033[33m"; // Yellow
		break;
	case LogLevel::ERROR:
		levelStr = "ERROR";
		colorCode = "\033[31m"; // Red
		break;
	}
	std::cout << colorCode << "[" << levelStr << "] " << message << resetCode << std::endl;
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
	}
	file << "[" << levelStr << "] " << message << std::endl;
}
