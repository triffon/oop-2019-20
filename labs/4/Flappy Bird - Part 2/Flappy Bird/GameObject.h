#pragma once
#include "Util.h"

class Game;
class Renderer;

class GameObject
{
protected:
	Vec2D position;
public:
	GameObject() = default;
	GameObject(const Vec2D& position): position(position) {}

	const Vec2D& getPosition() { return position; }

	virtual void init(Game* game) = 0;
	virtual void update(Game* game) = 0;
	virtual void render(Renderer* renderer) = 0;
};

