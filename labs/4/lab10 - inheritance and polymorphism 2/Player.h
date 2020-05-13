#pragma once
#include <string>

using namespace std;


class Player
{
	string name;
	int wins;
public:
	Player(const char* name) : name(name), wins(0) {};

	const string& getName() { return name; }
	int getWins() { return wins; }

	virtual ~Player() {};
	virtual bool guess(int number) { return false; }
	virtual void addWin() { ++wins; }
};
