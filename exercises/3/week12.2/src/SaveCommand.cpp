#include"SaveCommand.h"
#include<fstream>
#include<iostream>
string SaveCommand::execute(vector<string> args, int count){
	std::fstream file(args[0]);
	file << args[1];
	cout << "test "<< endl;
	return "";	
}
