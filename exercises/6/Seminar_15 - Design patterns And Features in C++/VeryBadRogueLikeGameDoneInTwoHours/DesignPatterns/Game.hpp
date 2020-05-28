#pragma once
#include "Monsters.hpp"
#include "Factories.hpp"
#include "Hero.hpp"
#include <fstream>
#include <iostream>
#include <Windows.h>
class Dungeon
{
public:
	Monster** monsters;
	size_t count;

public:
	Dungeon(MonsterFactory* factory, int monstersCount) :count(monstersCount)
	{
		monsters = new Monster * [count];
		for (size_t i = 0; i < count; i++)
		{
			monsters[i] = factory->createMonster();
		}
	}

	friend std::ostream& operator<<(std::ostream& out, Dungeon dungeon);
};

class Game
{
	Hero hero;
	Dungeon* dungeons[10];
	size_t size;

public:
	Game()
	{
		MonsterFactory* skeletonFactory = new RandomSkeletonMonsterFactory();
		dungeons[0] = new Dungeon(skeletonFactory, 2);
		dungeons[1] = new Dungeon(skeletonFactory, 4);
		dungeons[2] = new Dungeon(skeletonFactory, 8);
		size = 3;
	}
	void start()
	{
		std::cout << "Game started." << std::endl;
		for (size_t i = 0; i < size; i++)
		{
			std::cout << "Begin battle in dungeon " << i + 1 << "." << std::endl;
			std::cout << "Enemies in current dungeon: " << *(dungeons[i]) << std::endl;
			Sleep(1000);
			std::cout << "Initiating battle..." << std::endl;
			Sleep(1000);

			for (size_t j = 0; j < dungeons[i]->count; j++)
			{
				fight(hero, dungeons[i]->monsters[j]);
				Sleep(2000);
			}

		}
	}
	void fight(Hero& hero, Monster* monster)
	{
		std::cout << "Hero starts a fight with ";
		monster->deserialize(std::cout);
		std::cout << std::endl;
		while (hero.health > 0 && monster->health > 0)
		{
			if (hero.mana > 30)
			{
				hero.magicAtack(monster);
				Sleep(500);
				monster->attack(hero);
			}
			else
			{
				hero.normalAtack(monster);
				Sleep(500);
				monster->attack(hero);
			}
		}

		if (hero.health > 0)
		{
			std::cout << "Hero succesfully won the battle against ";
			monster->deserialize(std::cout);
			std::cout << std::endl << std::endl;
		}
		else
		{
			std::cout << "Hero died. Pump up his stats in the code..." << std::endl << std::endl;
		}
	}
};
