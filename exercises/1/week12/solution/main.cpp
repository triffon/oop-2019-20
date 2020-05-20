#include <iostream>
#include "ConsoleLogger.h"
#include "FileLogger.h"

int main()
{
	ConsoleLogger cl;

	cl.write(WARNING, "Warning test");

	cl << "Info test";


	FileLogger fl("log_file", 25);
	//fl.resize_file();

	for (size_t i = 0; i < 30; i++)
	{
		std::string msg = std::to_string(i);
		fl.write(WARNING, msg.c_str());
	}


	//fl.printLastNLines(3);

	fl.startFromBeginning();

	for (size_t i = 0; i < 4; i++)
	{
		std::string msg = std::to_string(i);
		fl.write(INFO, msg.c_str());
	}

	return 0;
}
