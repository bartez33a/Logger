#include "SinkFactory.h"
#include "FileSink.h"
#include "SinkConfig.h"

#include <exception>


std::unique_ptr<Sink> SinkFactory::MakeSink(const SinkConfig& config)
{
	switch (config.type)
	{
	case SinkType::eFile:
		if (config.filePath.has_value() == false)
		{
			throw std::invalid_argument("file path is required for File SinkType");
		}

		return std::make_unique<FileSink>(config.filePath.value());
		break;

	default:
		throw std::invalid_argument("Unsupported type");
		break;
	}
	

}
