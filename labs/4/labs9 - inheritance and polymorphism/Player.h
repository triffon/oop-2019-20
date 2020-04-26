#pragma once
#include <iostream>
using namespace std;
class Player
{
private:
	char name[30];
protected:
	int health;
public:
	Player(int health, const char* name);

	int getHealth() { return health; }
	const char* getName() const { return name; }

	virtual void print() {
		cout << "Name: " << name << endl << "Heath: " << health << endl;
	}
	virtual ~Player() {}
	virtual void takeDamage(int damage) { health -= damage; }
	virtual int getDamage() { return 0; }

};
