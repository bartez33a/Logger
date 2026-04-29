#pragma once

#include <memory>
#include <queue>
#include <thread>
#include <mutex>

#include "LogEntry.h"
#include "Sink.h"
#include "SinkConfig.h"


class LoggerWorker
{
public:
	LoggerWorker( const SinkConfig& config );
	~LoggerWorker();
	void Start();
	void Stop();
	void AddLogEntry(const LogEntry& entry);
	void Initialize(const SinkConfig& config);

private:
	void Loop();
	void Write(std::unique_lock<std::mutex>& lock);

	std::mutex m_mutex;
	std::condition_variable m_conditionVariable;
	std::thread m_thread;
	std::queue<LogEntry> m_entriesQueue;
	std::unique_ptr<Sink> m_pSink;
	std::atomic<bool> m_stop{ false };

};