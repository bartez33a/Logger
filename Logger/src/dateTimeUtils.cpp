#include "../include/dateTimeUtils.h"
#include <stdexcept>
#include <chrono>


std::string dateTimeUtils::getCurrentDate(const DateFormat format)
{
    const std::chrono::time_point now{ std::chrono::system_clock::now() };
    const std::chrono::year_month_day date{ std::chrono::floor<std::chrono::days>(now) };
    std::stringstream ss;


    const int year{ date.year() };
    const unsigned int month{ date.month() };
    const unsigned int day{ date.day() };

    switch (format)
    {
    case DateFormat::YYMMDD:
        ss <<  std::setfill('0')  << std::setw(4) << year << "." << std::setw(2) << month << "." <<  std::setw(2) << day;
        break;

    case DateFormat::DDMMYY:
        ss << std::setfill('0') << std::setw(2) << day << "." << std::setw(2) << month << "." << std::setw(4) << year;
        break;

    default:
        throw std::invalid_argument("Unsupported DateFormat");
    }

    return ss.str();
}

std::string dateTimeUtils::getCurrentTime(const TimeFormat format)
{
    std::string timeString;
    const std::chrono::time_point utcTime =  std::chrono::utc_clock::now();
    const auto utcTimeLimitedToSeconds = std::chrono::floor<std::chrono::seconds>(utcTime);

    switch (format)
    {
    case TimeFormat::HHMMSS:
        timeString = std::format("{:%T%z}", utcTimeLimitedToSeconds);
        break;

    case TimeFormat::HHMM:
        timeString = std::format("{:%R%z}", utcTimeLimitedToSeconds);
        break;

    default:
        throw std::invalid_argument("Unsupported TimeFormat");
    }

    return timeString;
}
