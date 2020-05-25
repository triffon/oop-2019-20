#pragma once
#include <fstream>
class Hero;
class Monster
{
public:
	int health;
	int mana;
	int strength;
	int agility;
	int intellect;

	Monster(int h, int m, int s, int a, int i)
		:health(h), mana(m), strength(s), agility(a), intellect(i) {}

	virtual void attack(Hero& hero) = 0;
	virtual void deserialize(std::ostream& out) = 0
	{
		out << "(Health: " << health << ", Mana: " << mana
			<< ",Str: " << strength << ", Agi: " << agility
			<< ", Int: " << intellect << ")";
	}
};
class MeeleMonster : public Monster
{
public:
	MeeleMonster(int h, int m, int s, int a, int i)
		:Monster(h, m, s, a, i) {}

	void attack(Hero& hero);

};
class RangedMonster : public Monster
{
public:
	RangedMonster(int h, int m, int s, int a, int i)
		:Monster(h, m, s, a, i) {}

	void attack(Hero& hero);

};
class MageMonster : public Monster
{
public:
	MageMonster(int h, int m, int s, int a, int i)
		:Monster(h, m, s, a, i) {}

	virtual void attack(Hero& hero);
};