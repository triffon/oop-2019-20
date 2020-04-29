#include "DropShip.h"
#include <iostream>
using namespace std;


DropShip::DropShip()
	:Starship("DropShip", 30)
{
	for (int i = 0; i < 20; i++)
	{
		drone[i] = new CombatDrone();
	}
}
void DropShip::delete_drones()
{
	if (!drones_dropped)
	{
		for (int i = 0; i < 20; i++)
		{
			delete drone[i];
		}
	}
}

DropShip::~DropShip()
{
	delete_drones();
}

void DropShip::attack()
{
	if (drones_dropped)
	{
		cout << "DropShip: drones dropped" << endl;
		return;
	}
	cout << "DropShip: dropping drones" << endl;
	delete_drones();
	drones_dropped = true;
}

void DropShip::printInfo()
{
	cout << "DropShip Info:" << endl;
	if (drones_dropped)
	{
		cout << "  drones dropped: yes" << endl;
	}
	else
	{
		cout << "  drones dropped: no" << endl;
	}

	cout << "  weight: " << weight_in_tons <<  endl;

}