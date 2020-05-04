#pragma once
#include "Starship.h"
#include "MotherShip.h"
#include <iostream>
using namespace std;


class Bomber : public Starship
{
private:
	//<<<< забраняване на класа да се инстанцира и копира
	Bomber();
	Bomber& operator=(const Bomber &other) = delete;
	Bomber(const Bomber &other) = delete;
	//<<<<

	struct Bomb {
		int damage = 10;
	};
	Bomb *bombs[10];
	int bombs_count = 10;


public:
	virtual void attack() override;
	virtual void printInfo() override;

	virtual ~Bomber();
	friend class MotherShip;
};