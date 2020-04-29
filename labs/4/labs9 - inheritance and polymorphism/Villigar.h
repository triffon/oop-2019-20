#pragma once
#include "Player.h"

class Villager : public Player
{
public:
	Villager() : Player(50, "Villager"){}

	// Player overrides
	int getDamage() override { return 0; }
};
