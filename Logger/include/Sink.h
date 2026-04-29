#pragma once

#include <string>

enum class SinkType
{
	eFile
};

class Sink
{
public:
	virtual ~Sink() = 0 {}
	virtual void writeLine(const std::string& text) = 0;
};