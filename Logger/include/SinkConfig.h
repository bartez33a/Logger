#pragma once

#include "Sink.h"
#include <optional>

struct  SinkConfig
{
	SinkType type;
	std::optional<std::string> filePath;
};