#pragma once
#include "Monsters.hpp"
class Hero
{
public:
	int health;
	int mana;
	int strength;
	int agility;
	int intellect;

	Hero();
	void normalAtack(Monster* monster);
	void magicAtack(Monster* monster);
};