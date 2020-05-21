#include<algorithm>
#include<cstring>
#include<vector>
#include"Crow.h"
#include"Penguin.h"
#include<iostream>
#include<map>
#include"Command.h"
#include"ReadCommand.h"
#include"SaveCommand.h"
using namespace std;

void fillMap(map<string, Command *>& m){
	m.insert(m.begin(),pair<string, Command *>("save",new SaveCommand()));
	m.insert(m.begin(),pair<string, Command *>("read", new ReadCommand()));
	// insert more commands here
}
vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}
int main(){
	map<string,Command *> m;
	fillMap(m);
	string input;
	while(true){
		cin >> input;
		vector<string> arguments = split(input," ");
		if(count(m.begin(),m.end(),arguments[0])){
			m[arguments[0]]->execute(arguments,arguments.size());
		}
		cout << "fasdfa" << endl;
	}
	return 0;
}

