#pragma once

#include <string>

class Logger
{
public:

	enum class LogLevel
	{
		eTrace,
		eDebug,
		eInfo,
		eWarning,
		eError,
		eFatalError,
	};


	void init_logger(std::string logFilePath);
	void log_info(const std::string& message);
	void log_warning(const std::string& message);
	void log_error(const std::string& message);

	void set_log_level(LogLevel level);

private:
	Logger();

	// not available c-tors
	Logger(const Logger&) = delete;
	Logger(const Logger&&) = delete;

	// not available operators
	Logger& operator=(const Logger&) = delete;
	Logger& operator=(const Logger&&) = delete;
};



