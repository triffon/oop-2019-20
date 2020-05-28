#pragma once
#include "GameObject.h"

class Bot : public GameObject
{
	int findShortestPath(Position currentPos, Position target, char** map, int depth);
public:
	void update() override;
	void render() override;
};
