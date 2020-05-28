#include "GameObject.h"
#include "Maze.h"

void GameObject::tryMove(int x, int y)
{
	if (!maze->isObsticle(x, y)) {
		move(x, y);
	}
}
