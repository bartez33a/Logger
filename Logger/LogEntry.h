#pragma once

#include <string>

class LogEntry
{
public:
	LogEntry(const std::string& dateString, const std::string& timeString, const std::string& levelString, const std::string& message);

private:
	std::string m_date;
	std::string m_time;
	std::string m_level;
	std::string m_message;
};