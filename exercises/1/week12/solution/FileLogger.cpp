#include "FileLogger.h"

FileLogger::FileLogger(const char *filename, int lines_limit)
	:m_log_file(filename, std::ios::in | std::ios::out | std::ios::trunc),
	m_lines_limit(lines_limit), m_filename(filename)
{
	m_log = &m_log_file;
}

void FileLogger::setLineLimit(int n)
{
	m_lines_limit = n;
}

void FileLogger::write(LogType type, const char *msg)
{
	if (m_lines >= m_lines_limit)
	{
		resize_file();
	}
	Logger::write(type, msg);
	m_lines++;
}


void FileLogger::seek_n_lines_back(int n, std::ifstream *strm)
{
	int line_count = 0;
	int pos = -1;
	do {
		strm->seekg(pos--, std::ios::end);
		char c;
		strm->get(c);

		if (c == '\n')
		{
			line_count++;
			//'\r''\n' 
			//comment if using Linux\MacOS
			pos--;
		}


	} while (strm->tellg() > 0  && line_count <= n);

}


void FileLogger::resize_file()
{
	m_log_file.close();
	std::string tmp_filename = m_filename + "_tmp";
	std::rename(m_filename.c_str(), tmp_filename.c_str());


	std::ifstream tmp_file(tmp_filename);
	seek_n_lines_back(m_lines_limit / 5, &tmp_file);

	m_log_file.open(m_filename, std::ios::in | std::ios::out | std::ios::trunc);

	std::string line;
	while (std::getline(tmp_file, line))
	{
		m_log_file << line << std::endl;
	}

	tmp_file.close();
	std::remove(tmp_filename.c_str());

	m_lines = m_lines_limit / 5;

}


void FileLogger::printLastNLines(int n)
{
	std::cout << "Last " << n << "lines: \n";
	seek_n_lines_back(n, (std::ifstream*)&m_log_file);
	std::string line;
	while (std::getline(m_log_file, line))
	{
		std::cout << line << std::endl;
	}
}


void FileLogger::startFromBeginning()
{
	m_log_file.seekp(0, std::ios::beg);
}