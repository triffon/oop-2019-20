#include "Soldier.h"
#include <cstring>

Soldier::Soldier()
	: Player(100, "Soldier"), armor(100), attackDamage(50)
{
}

Soldier::Soldier(int armor, int attackDamage)
	: Player(100, "Soldier"), armor(armor), attackDamage(attackDamage)
{
}

Soldier::Soldier(int armor, int attackDamage, int health)
	: Player(health, "Soldier"), armor(armor), attackDamage(attackDamage)
{
}

void Soldier::takeDamage(int damage)
{
	Player::takeDamage(damage / 2);
	armor -= damage / 2;
}
