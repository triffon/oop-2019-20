#pragma once
#include <iostream>
#include "Player.h"

class Soldier: public Player
{
	int attackDamage;
	int armor;
public:
	Soldier();
	Soldier(int armor, int attackDamage);
	Soldier(int armor, int attackDamage, int health);
	int getArmor() { return armor; }

	// Player overrides
	int getDamage() override { return attackDamage; }
	void takeDamage(int damage) override;
	void print() override {
		Player::print();
		cout << "Attack damage: " << attackDamage << endl << "Armor: " << armor << endl;
	}
};
