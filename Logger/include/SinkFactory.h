#pragma once

#include "Sink.h"
#include "SinkConfig.h"
#include <memory>

class SinkFactory
{
public:
	static std::unique_ptr<Sink> MakeSink(const SinkConfig& config);
};