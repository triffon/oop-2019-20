#include "Bot.h"
#include "Maze.h"
#include <iostream>
using namespace std;
// ..P..
// .....
// .##..
// .....
// .B...

const int NO_PATH = 99999999;
const int MAX_DEPTH = 8;

Position directions[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

// We use DFS for searching
int Bot::findShortestPath(Position currentPos, Position target, char** map, int depth)
{
	if (depth > MAX_DEPTH ||
		currentPos.x < 0 ||
		currentPos.y < 0 ||
		currentPos.x >= Maze::MAZE_WIDTH ||
		currentPos.y >= Maze::MAZE_HEIGHT ||
		map[currentPos.y][currentPos.x] == '#' ||
		map[currentPos.y][currentPos.x] == 'v')
		return NO_PATH;

	if (currentPos == target) {
		return depth;
	}

	map[currentPos.y][currentPos.x] = 'v';

	int bestResult = NO_PATH;
	for (int i = 0; i < 4; ++i) {
		Position nextPos = { currentPos.x + directions[i].x, currentPos.y + directions[i].y };
		int currentResult = findShortestPath(nextPos, target, map, depth + 1);
		if (bestResult > currentResult)
			bestResult = currentResult;
	}
	map[currentPos.y][currentPos.x] = '.';
	return bestResult;
}

void Bot::update()
{
	Position playerPos = maze->getPlayerPosition();
	char** mapCpy = maze->getMapCopy();
	int bestResult = NO_PATH;
	int directionIdx = -1;
	for (int i = 0; i < 4; ++i) {
		Position nextPos = { pos.x + directions[i].x, pos.y + directions[i].y };
		int currentResult = findShortestPath(nextPos, playerPos, mapCpy, 0);
		if (bestResult > currentResult) {
			bestResult = currentResult;
			directionIdx = i;
		}
	}
	if (directionIdx != -1) {
		tryMove(pos.x + directions[directionIdx].x, pos.y + directions[directionIdx].y);
	}
	maze->destroyMap(mapCpy);
}

void Bot::render()
{
	maze->getMap()[pos.y][pos.x] = 'B';
}
