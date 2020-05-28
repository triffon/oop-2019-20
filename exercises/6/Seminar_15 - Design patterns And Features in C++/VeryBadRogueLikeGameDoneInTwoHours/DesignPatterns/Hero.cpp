#include "Hero.hpp"
#include <iostream>

Hero::Hero()
{
	health = 360;
	mana = 120;
	strength = 50;
	agility = 50;
	intellect = 50;
}

void Hero::normalAtack(Monster* monster)
{
	int damage = 2 * (strength + agility);
	std::cout << "Hero deals " << damage << " with normal atack! Heals for 5 health and 10 mana!" << std::endl;
	monster->health -= damage;
	mana += 10;
	health += 5;
}

void Hero::magicAtack(Monster* monster)
{
	if (mana > 30)
	{
		int damage = 5 * intellect + strength + agility;
		std::cout << "Hero deals " << damage << " with magic atack!" << std::endl;
		monster->health -= damage;
		mana -= 30;
	}
	else
	{
		std::cout << "Hero has no mana to ues magic atack!" << std::endl;
	}
}

