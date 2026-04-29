#include "LogEntry.h"



LogEntry::LogEntry(const std::string& dateString, const std::string& timeString, const std::string& levelString, const std::string& message) :
	m_date{ dateString }, m_time{ timeString }, m_level{ levelString }, m_message{ message } {
}

LogEntry::operator std::string()
{
	return m_date + " " + m_time + " " + m_level + " " + m_message;
}
