#pragma once
#include "Skeletons.hpp"
#include <time.h>
class MonsterFactory
{
public:
	virtual Monster* createMonster() = 0;
};

class RandomSkeletonMonsterFactory : public MonsterFactory
{
public:
	Monster* createMonster()
	{
		srand(time(nullptr));
		int randomNumber = rand() % 3;

		switch (randomNumber)
		{
		case 0:
			return new SkeletonWarrior();
		case 1:
			return new SkeletonArcher();
		case 2:
			return new SkeletonMage();
		}

		return new SkeletonWarrior();
	}
};