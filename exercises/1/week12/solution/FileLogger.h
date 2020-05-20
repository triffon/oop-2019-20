#pragma once

#include "Logger.h"
#include <string>
#include <fstream>

class FileLogger : public Logger
{
	int m_lines = 0;
	int m_lines_limit = 0;
	std::string m_filename;
	std::fstream m_log_file;
	void seek_n_lines_back(int n, std::ifstream *strm);
	void resize_file();
public:
	FileLogger(const char *filename, int lines_limit);
	void setLineLimit(int n);
	void write(LogType type, const char *msg) override;

	void printLastNLines(int n);

	void startFromBeginning();
};