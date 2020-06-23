#pragma once
#include <queue>
#include "GameObject.h"
#include "Util.h"

class PipeSpawner: public GameObject
{
	std::vector<Vec2D> pipes;
	float pipeHDistance;
	float pipeVDistance;

public:
	PipeSpawner();

	virtual void update(Game* game) override;
	virtual void render(Renderer* game) override;
	virtual void init(Game* game) override;
};

