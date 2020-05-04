#pragma once
#include "Starship.h"

#include "MotherShip.h"

class DropShip : public Starship
{
	//<<<< забраняване на класа да се инстанцира и копира
	DropShip();
	DropShip(const DropShip &other) = delete;
	DropShip& operator=(const DropShip &other) = delete;
	//<<<<

	struct CombatDrone {
		int damage = 2;
	};
	CombatDrone *drone[20];
	bool drones_dropped = false;

	void delete_drones();
public:
	virtual void attack() override;
	virtual void printInfo() override;
	virtual ~DropShip();

	friend class MotherShip;
};
