#pragma once
#include <string>

namespace dateTimeUtils
{
	enum class DateFormat
	{
		YYMMDD,
		DDMMYY
	};

	enum class TimeFormat
	{
		HHMMSS,
		HHMM
	};

	std::string getCurrentDate(const DateFormat format);
	std::string getCurrentTime(const TimeFormat format);
}