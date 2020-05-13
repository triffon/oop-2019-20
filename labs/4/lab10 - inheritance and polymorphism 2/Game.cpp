#include "Game.h"
#include "PlayerTypes.h"
#include <time.h>
#include <iostream>

using namespace std;

void Game::init(int numAIPlayers, int humanPlayers, int rounds)
{
	this->rounds = rounds;
	for (int i = 0; i < humanPlayers; ++i) {
		players.push_back(new HumanPlayer());
	}

	for (int i = 0; i < numAIPlayers; ++i) {
		if (i % 3 == 0)
			players.push_back(new RandomAIPlayer());
		else if(i % 3 == 1)
			players.push_back(new DumbAIPlayer());
		else players.push_back(new SmartAIPlayer());
	}
}

int Game::generateRandomNumber(int min, int max)
{
	return min + rand() % (max - min);
}

void Game::handlePlayerTurn(Player* player, int randNumber, int nextNumber)
{
	cout << "It is player " << player->getName() << "'s turn" << endl;
	bool guess = player->guess(randNumber);
	const char* choice = guess ? "up" : "down";
	cout << "Player " << player->getName() << " chose "<< choice << endl;
	if (guess == nextNumber >= randNumber) {
		player->addWin();
	}
}

int Game::handleRound(int randNumber)
{
	int nextNumber = generateRandomNumber(0, 100);
	for (int playerIdx = 0; playerIdx < players.size(); ++playerIdx) {
		Player* nextPlayer = players[playerIdx];
		handlePlayerTurn(nextPlayer, randNumber, nextNumber);
	}
	return nextNumber;
}

int Game::getBestScore()
{
	int bestScore = players[0]->getWins();
	for (int i = 1; i < players.size(); ++i) {
		if (bestScore < players[i]->getWins()) {
			bestScore = players[i]->getWins();
		}
	}
	return bestScore;
}

void Game::finish()
{
	cout << "Game ended!" << endl << "Winners:";
	int bestScore = getBestScore();
	for (int i = 0; i < players.size(); ++i) {
		if (players[i]->getWins() == bestScore)
			cout << " " << players[i]->getName();
	}
}

Game::Game()
{
	init(1, 1, 5);
}

Game::Game(int aiPlayers, int humanPlayers, int rounds)
{
	init(aiPlayers, humanPlayers, rounds);
}

void Game::play()
{
	srand(time(NULL));
	cout << "Game Started" << endl;
	int randNumber = generateRandomNumber(0, 100);
	for (int round = 0; round < rounds; ++round) {
		randNumber = handleRound(randNumber);
	}
	finish();
}

Game::~Game()
{
	for (int i = 0; i < players.size(); ++i) {
		delete players[i];
	}
}
