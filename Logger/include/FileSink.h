#pragma once

#include <fstream>
#include <string>
#include <optional>

#include "Sink.h"


class FileSink : public Sink
{
public:
	FileSink(const std::string& filePath);
	~FileSink();

	void writeLine(const std::string& text);

private:
	std::string m_filePath;
	std::ofstream m_stream;
};