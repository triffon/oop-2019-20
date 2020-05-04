#include "MotherShip.h"
#include "Starship.h"
#include "DropShip.h"
#include "Interceptor.h"
#include "Bomber.h"

#include <iostream>
using namespace std;


template<typename Ship>
Ship* MotherShip::createShip()
{
	Ship *sh = nullptr;
	if (ships_in_hangar < hangar_capacity)
	{
		sh = new Ship();
		hangar[ships_in_hangar++] = sh;
	}
	else
	{
		cout << "Mothership: Not enough room in hangar to create nwe ship!" << endl;
	}
	return sh;
}

DropShip* MotherShip::createDropShip()
{
	return createShip<DropShip>();
}

Interceptor* MotherShip::createInterceptor()
{
	return createShip<Interceptor>();
}

Bomber* MotherShip::createBomber()
{
	return createShip<Bomber>();
}

MotherShip::MotherShip()
{
	hangar = new Starship*[hangar_capacity];
	for (int i = 0; i < hangar_capacity; i++)
	{
		hangar[i] = nullptr;
	}
}



MotherShip::~MotherShip()
{
	
	for (int i = 0; i < hangar_capacity; i++)
	{
		if (hangar[i] != nullptr)
		{
			delete hangar[i];
		}
		
	}
	delete[] hangar;
}

void MotherShip::printStarshipInfo()
{
	cout << "Mothership Info: " << endl;
	for (int i = 0; i < ships_in_hangar; i++)
	{
		cout << "hangar[" << i<<"]: " << endl;
		hangar[i]->printInfo();
	}
}

MotherShip& MotherShip::getIntsance()
{
	static MotherShip mothership;
	
	return mothership;
}