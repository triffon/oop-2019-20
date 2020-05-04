#pragma once

//class Starship;
#include "Starship.h"

class DropShip;
class Interceptor;
class Bomber;

class MotherShip
{
	const int hangar_capacity = 20;
	int ships_in_hangar = 0;
	Starship **hangar;

	//<<<< забраняване на класа да се инстанцира и копира
	MotherShip(const MotherShip & other) = delete;
	MotherShip& operator=(const MotherShip & other) = delete;
	MotherShip();
	//<<<<
	
	template<typename Ship>
	Ship* createShip();
public:
	DropShip* createDropShip();
	Interceptor* createInterceptor();
	Bomber* createBomber();

	void printStarshipInfo();
	~MotherShip();
	
	// връща единствената инстанция на класа
	static MotherShip& getIntsance();
};
