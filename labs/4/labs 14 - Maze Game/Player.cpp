#include <iostream>
#include "Player.h"
#include "Maze.h"

using namespace std;

void Player::update()
{
	cout << "Enter U/D/L/R for direction ";
	char dir;
	cin >> dir;
	if (dir == 'L')
		tryMove(pos.x - 1, pos.y);
	else if (dir == 'R')
		tryMove(pos.x + 1, pos.y);
	else if (dir == 'U')
		tryMove(pos.x, pos.y - 1);
	else if (dir == 'D')
		tryMove(pos.x, pos.y + 1);
}

void Player::render()
{
	maze->getMap()[pos.y][pos.x] = 'P';
}
