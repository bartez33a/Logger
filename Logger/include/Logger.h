#pragma once

#include <string>
#include <fstream>
#include <memory>
#include <queue>
#include <thread>

#include "LoggerWorker.h"

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



	~Logger();

	static std::shared_ptr<Logger> get();
	void init_logger(const SinkConfig& config);

	void log_trace(const std::string& message);
	void log_debug(const std::string& message);
	void log_info(const std::string& message);
	void log_warning(const std::string& message);
	void log_error(const std::string& message);
	void log_fatal_error(const std::string& message);

	void set_log_level(LogLevel level);

private:
	// not available c-tors
	Logger(const SinkConfig& config);

	// deleted c-tors
	Logger(const Logger&) = delete;
	Logger(const Logger&&) = delete;

	// deleted operators
	Logger& operator=(const Logger&) = delete;
	Logger& operator=(const Logger&&) = delete;

	// members
	LoggerWorker m_loggerWorker;

	static const std::string m_defaultLogPath;
	static const SinkConfig m_defaultConfig;

	LogLevel m_logLevel = { LogLevel::eInfo };
};





