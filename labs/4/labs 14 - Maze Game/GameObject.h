#pragma once
#include "Utils.h"

class Maze;

class GameObject
{
protected:
	Maze* maze;
	Position pos;

	void tryMove(int x, int y);

public:

	virtual void update() = 0;
	virtual void render() = 0;

	virtual ~GameObject() {}
	void setPosition(const Position& pos) {
		this->pos = pos;
	}
	const Position& getPosition() {
		return pos;
	}

	void setMaze(Maze* maze) {
		this->maze = maze;
	}

	void move(int x, int y) {
		pos = { x, y };
	}
};

