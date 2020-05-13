#pragma once
#include <vector>
#include "Player.h"

using namespace std;

class Game
{
	vector<Player*> players;
	int rounds;

	void init(int numAIPlayers, int humanPlayers, int rounds);
	int generateRandomNumber(int min, int max);
	void handlePlayerTurn(Player* player, int randNumber, int nextNumber);
	int handleRound(int randNumber);
	int getBestScore();
	void finish();
public:

	Game();
	Game(int aiPlayers, int humanPlayers, int rounds);
	void play();

	~Game();

};

