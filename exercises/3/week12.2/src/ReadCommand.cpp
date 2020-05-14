#include <fstream>
#include <iostream>
#include "ReadCommand.h"
string ReadCommand::execute(vector<string> args, int count){
	std::fstream file(args[0]);	
	string buffer;
	file>>buffer;
	std::cout << buffer;
	return "";
}
