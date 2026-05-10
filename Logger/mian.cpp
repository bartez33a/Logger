#include <iostream>

#include "Logger.h"

#include "dateTimeUtils.h"

int main()
{
	Logger::get()->log_warning("test");

	return 0;
}