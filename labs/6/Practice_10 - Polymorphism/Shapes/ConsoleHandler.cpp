#include <iostream>
#include <string>

#include "ConsoleHandler.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

ConsoleHandler::ConsoleHandler(string fileName)
{
	std::ifstream in(fileName);
	if (!in.is_open())
	{
		string message = "Could not open " + fileName;
		throw message;
	}

	in >> shapes;
}

void ConsoleHandler::start()
{
	std::cout << "Console handler started." << std::endl;

	string command;
	cin >> command;
	if (command == "perimeter")
	{
		shapes.printPerimeters();
	}
}
