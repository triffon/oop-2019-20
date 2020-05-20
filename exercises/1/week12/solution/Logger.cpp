#include "Logger.h"

Logger::Logger() :m_log(nullptr)
{}


const char* Logger::log_types[] = {
	"WARNING",
	"ERROR",
	"DEBUG",
	"INFO"
};


void Logger::write(LogType type, const char *msg)
{
	if (m_log != nullptr)
	{
		(*m_log) << log_types[type] << ": " << msg << std::endl;
	}
}