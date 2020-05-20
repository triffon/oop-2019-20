#pragma once
#include <iostream>

enum LogType
{
	WARNING, ERROR, DEBUG, INFO
};



class Logger
{
	static const char *log_types[];
protected:
	std::ostream *m_log;
public:
	Logger();
	virtual void write(LogType type, const char *msg);
};