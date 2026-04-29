#include "Logger.h"
#include <thread>
#include "dateTimeUtils.h"
#include <exception>




static LogEntry prepareLogEntry(Logger::LogLevel level, const std::string& message) {
	const std::string date = dateTimeUtils::getCurrentDate(dateTimeUtils::DateFormat::DDMMYY);
	const std::string time = dateTimeUtils::getCurrentTime(dateTimeUtils::TimeFormat::HHMM);
	std::string levelString;

	switch (level)
	{
	case Logger::LogLevel::eTrace:
		levelString = "TRACE";
		break;

	case Logger::LogLevel::eDebug:
		levelString = "DEBUG";
		break;

	case Logger::LogLevel::eInfo:
		levelString = "INFO";
		break;

	case Logger::LogLevel::eWarning:
		levelString = "WARNING";
		break;

	case Logger::LogLevel::eError:
		levelString = "ERROR";
		break;

	case Logger::LogLevel::eFatalError:
		levelString = "FATAL ERROR";
		break;

	default:
		throw std::invalid_argument("Not supported Logger::LogLevel");
		break;
	}

	return LogEntry{ date, time, levelString, message };
}

const std::string Logger::m_defaultLogPath{ "log.txt" };
const SinkConfig Logger::m_defaultConfig{ SinkType::eFile, m_defaultLogPath };

Logger::Logger(const SinkConfig& config) : m_loggerWorker(config)
{

}


Logger::~Logger()
{
}

std::shared_ptr<Logger> Logger::get()
{
	static std::shared_ptr<Logger> pLogger{ nullptr };
	if (!pLogger)
	{
		pLogger = std::shared_ptr<Logger>(new Logger(m_defaultConfig));
	}

	return pLogger;
}

void Logger::init_logger( const SinkConfig& config )
{
	m_loggerWorker.Initialize(config);
}

void Logger::log_trace(const std::string& message)
{
	if (m_logLevel > LogLevel::eTrace)
	{
		return;
	}

	m_loggerWorker.AddLogEntry(prepareLogEntry(LogLevel::eTrace, message));
}

void Logger::log_debug(const std::string& message)
{
	if (m_logLevel > LogLevel::eDebug)
	{
		return;
	}

	m_loggerWorker.AddLogEntry(prepareLogEntry(LogLevel::eDebug, message));
}

void Logger::log_info(const std::string& message)
{
	if (m_logLevel > LogLevel::eInfo)
	{
		return;
	}

	m_loggerWorker.AddLogEntry(prepareLogEntry(LogLevel::eInfo, message));

}

void Logger::log_warning(const std::string& message)
{
	if (m_logLevel > LogLevel::eWarning)
	{
		return;
	}

	m_loggerWorker.AddLogEntry(prepareLogEntry(LogLevel::eWarning, message));
}

void Logger::log_error(const std::string& message)
{
	if (m_logLevel > LogLevel::eError)
	{
		return;
	}

	m_loggerWorker.AddLogEntry(prepareLogEntry(LogLevel::eError, message));
}

void Logger::log_fatal_error(const std::string& message)
{
	m_loggerWorker.AddLogEntry(prepareLogEntry(LogLevel::eFatalError, message));
}

void Logger::set_log_level(LogLevel level)
{
	m_logLevel = level;
}





