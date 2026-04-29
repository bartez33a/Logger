#include "LoggerWorker.h"
#include "SinkFactory.h"

#include <exception>

LoggerWorker::LoggerWorker(const SinkConfig& config) : 
	m_pSink{ SinkFactory::MakeSink(config) }, 
	m_stop{false}
{
	Start();
}

LoggerWorker::~LoggerWorker()
{
	Stop();
}

void LoggerWorker::Start()
{
	Stop();

	{
		std::unique_lock<std::mutex> lock(m_mutex);
		m_stop = { false };
	}

	m_thread = std::thread(&LoggerWorker::Loop, this);
}

void LoggerWorker::Stop()
{
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		m_stop = true;
	}

	m_conditionVariable.notify_one(); 

	if (m_thread.joinable())
	{
		m_thread.join();
	}
}

void LoggerWorker::AddLogEntry(const LogEntry& entry)
{
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		m_entriesQueue.emplace(entry);
	}

	m_conditionVariable.notify_one();
}

void LoggerWorker::Initialize(const SinkConfig& config)
{
	Stop();
	m_pSink = SinkFactory::MakeSink(config);
	Start();
	
}

void LoggerWorker::Loop()
{
	std::unique_lock<std::mutex> lock(m_mutex);

	while ( true )
	{
		m_conditionVariable.wait(lock, [&] {
			return !m_entriesQueue.empty() || m_stop;
			});

		while (!m_entriesQueue.empty())
		{
			Write(lock);
		}
		
		if (m_stop)
		{
			break;
		}
	}
}

void LoggerWorker::Write(std::unique_lock<std::mutex>& lock)
{
	if (m_pSink)
	{
		auto entry = std::move(m_entriesQueue.front());
		m_entriesQueue.pop();

		lock.unlock();
		m_pSink->writeLine(entry);
		lock.lock();
		
	}
}
