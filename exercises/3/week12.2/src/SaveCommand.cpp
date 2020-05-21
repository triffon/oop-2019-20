#include"SaveCommand.h"
#include<fstream>
#include<iostream>
using namespace std;
string SaveCommand::execute(vector<string> args, int count){
	std::fstream file(args[1]);
	file << args[2];
	return "";	
}
