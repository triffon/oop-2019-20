#include "Monsters.hpp"
#include "Hero.hpp"

void MeeleMonster::attack(Hero& hero)
{
	hero.health -= 2 * strength + agility;
}

void RangedMonster::attack(Hero& hero)
{
	hero.health -= 2 * agility;
}

void MageMonster::attack(Hero& hero)
{
	hero.health -= 2 * intellect;
}
