#pragma once
#include "Player.h"

class HumanPlayer : public Player {
public:
	HumanPlayer() : Player("Human") {}

	bool guess(int number) override;
};

class RandomAIPlayer : public Player {
public:
	RandomAIPlayer() : Player("RandomAIPlayer") {}

	bool guess(int number) override;
};

class SmartAIPlayer : public Player {
public:
	SmartAIPlayer() : Player("Smart guy") {}

	bool guess(int number) override;
};

class DumbAIPlayer : public Player {
public:
	DumbAIPlayer() : Player("Dumb guy") {}

	bool guess(int number) override;
};
