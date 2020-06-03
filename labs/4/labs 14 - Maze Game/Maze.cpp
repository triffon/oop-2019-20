#include <iostream>
#include "GameObject.h"
#include "Player.h"
#include "Bot.h"
#include "Maze.h"
using namespace std;

void Maze::renderMap()
{
	for (int i = 0; i < MAZE_HEIGHT; ++i) {
		for (int j = 0; j < MAZE_WIDTH; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

void Maze::clearMap()
{
	for (int i = 0; i < MAZE_HEIGHT; ++i) {
		for (int j = 0; j < MAZE_WIDTH; ++j) {
			if (map[j][i] != '#' && map[j][i] != '.') {
				map[j][i] = '.';
			}
		}
	}
}

bool Maze::isObsticle(int x, int y)
{
	return x < 0 || y < 0 || x >= MAZE_WIDTH || y >= MAZE_HEIGHT || map[y][x] == '#';
}

void Maze::init()
{
	map = new char* [MAZE_HEIGHT];
	for (int i = 0; i < MAZE_HEIGHT; ++i) {
		map[i] = new char[MAZE_WIDTH];
		for (int j = 0; j < MAZE_WIDTH; ++j) {
			map[i][j] = '.';
		}
	}

	player = new Player();
	player->setMaze(this);
	player->setPosition({ 0, 0 });

	GameObject* bot = new Bot();
	bot->setMaze(this);
	bot->setPosition({ 9, 4 });

	gameObjects.push_back(player);
	gameObjects.push_back(bot);


	map[2][0] = '#';
	map[2][1] = '#';
	map[2][2] = '#';
	map[2][3] = '#';
	map[2][5] = '#';
	map[2][6] = '#';
	map[2][7] = '#';
	map[2][8] = '#';
	map[2][9] = '#';
	map[3][5] = '#';
	map[4][5] = '#';
	map[5][5] = '#';
	map[6][5] = '#';
}

void Maze::render()
{
	clearMap();
	for (int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->render();
	}
	renderMap();
}

void Maze::update()
{
	for (int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->update();
	}
}

char** Maze::getMapCopy()
{
	char** cpy = new char* [MAZE_HEIGHT];
	for (int i = 0; i < MAZE_HEIGHT; ++i) {
		cpy[i] = new char[MAZE_WIDTH];
		for (int j = 0; j < MAZE_WIDTH; ++j) {
			cpy[i][j] = map[i][j];
		}
	}
	return cpy;
}

void Maze::destroyMap(char** map)
{
	for (int i = 0; i < MAZE_HEIGHT; ++i) {
		delete[] map[i];
	}
	delete[] map;
}

Position Maze::getPlayerPosition()
{
	return player->getPosition();
}

Maze::~Maze()
{
	for (int i = 0; i < gameObjects.size(); ++i) {
		delete gameObjects[i];
	}
	destroyMap(map);
}
