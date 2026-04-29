#include <iostream>

#include "Logger.h"


int main()
{
	Logger::get()->log_warning("test");

	return 0;
}