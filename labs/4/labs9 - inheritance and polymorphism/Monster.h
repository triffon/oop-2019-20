#pragma once
#include "Player.h"

class Monster: public Player
{
	int attackDamage;
public:
	Monster();

	// Player overrides
	int getDamage() override { return attackDamage; }
};

