#pragma once
#include "Monsters.hpp"

class SkeletonWarrior : public MeeleMonster
{
public:
	SkeletonWarrior(int h = 50, int m = 0, int s = 25, int a = 15, int i = 5)
		:MeeleMonster(h, m, s, a, i) {}
	void deserialize(std::ostream& out)
	{
		out << "Skeleton Warrior";
		Monster::deserialize(out);
	}
};

class SkeletonArcher : public RangedMonster
{
public:
	SkeletonArcher(int h = 20, int m = 10, int s = 10, int a = 30, int i = 10)
		:RangedMonster(h, m, s, a, i) {}
	void deserialize(std::ostream& out)
	{
		out << "Skeleton Archer";
		Monster::deserialize(out);
	}
};

class SkeletonMage : public MageMonster
{
public:
	SkeletonMage(int h = 10, int m = 50, int s = 5, int a = 15, int i = 45)
		:MageMonster(h, m, s, a, i) {}
	void deserialize(std::ostream& out)
	{
		out << "Skeleton Mage";
		Monster::deserialize(out);
	}
};