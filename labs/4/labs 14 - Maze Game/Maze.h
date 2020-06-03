#pragma once
#include <vector>
#include "Utils.h"

class GameObject;
class Player;

class Maze
{
	Player* player;
	char** map;
	std::vector<GameObject*> gameObjects;

	void renderMap();
	void clearMap();
public:
	static const int MAZE_WIDTH = 10;
	static const int MAZE_HEIGHT = 10;

	bool isObsticle(int x, int y);
	char** getMap() { return map; }
	void init();
	void render();
	void update();
	char** getMapCopy();
	void destroyMap(char** map);
	Position getPlayerPosition();
	~Maze();
};

