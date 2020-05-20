#pragma once

#include "Logger.h"

class ConsoleLogger : public Logger
{
public:
	ConsoleLogger()
	{
		m_log = &std::cout;
	}

	std::ostream& operator<<(const char *msg)
	{
		Logger::write(INFO, msg);

		return *m_log;
	}
};
