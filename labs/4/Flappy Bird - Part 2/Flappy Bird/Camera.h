#pragma once
#include "Util.h"
#include "Renderer.h"

class GameObject;

class Camera
{
	Vec2D position;
	Vec2D scale;
	Vec2D viewSize;
	Renderer* renderer;

	GameObject* target;
public:
	Camera(Renderer* renderer);

	void setPosition(const Vec2D& pos) { position = pos; }
	void update();

	void setTarget(GameObject* object) { target = object; }

	const Vec2D& getSize() { return viewSize; }
	const Vec2D& getPosition() { return position; }
	const Vec2D& getScale() { return scale; }
};

