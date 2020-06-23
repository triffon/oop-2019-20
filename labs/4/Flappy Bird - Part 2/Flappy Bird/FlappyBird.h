#pragma once
#include "GameObject.h"
#include "Model.h"

class FlappyBird: public GameObject
{
	float accelration;
	float sideSpeed;
	Model model;
public:
	FlappyBird();

	virtual void init(Game* game) override;
	virtual void update(Game* game) override;
	virtual void render(Renderer* renderer) override;
};

