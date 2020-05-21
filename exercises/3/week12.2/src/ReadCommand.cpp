#include <fstream>
#include <iostream>
#include "ReadCommand.h"
string ReadCommand::execute(vector<string> args, int count){
	std::fstream file(args[1]);	
	string buffer;
	file>>buffer;
	cout << buffer;
	return "";
}
