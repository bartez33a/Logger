#pragma once

#include "FileSink.h"


FileSink::FileSink(const std::string& filePath) : m_filePath{ filePath } {
	m_stream.open(filePath, std::ios::app);
	if (m_stream.is_open() == false)
	{
		throw std::fstream::failure("Cannot open file stream");
	}
}

FileSink::~FileSink()
{
	if (m_stream.is_open()) 
	{
		m_stream.close();
	}
}

void FileSink::writeLine(const std::string& text)
{
	if (m_stream.is_open())
	{
		m_stream << text << "\n";
	}
}

