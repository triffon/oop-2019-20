#include "Camera.h"
#include "GameObject.h"

Camera::Camera(Renderer* renderer) : 
	position({ 0,0 }),
	scale({1,1}),
	renderer(renderer),
	viewSize({1000, 800}) {}

void Camera::update()
{
	Vec2D resolution = renderer->getResolution();
	scale = { resolution.x / viewSize.x, resolution.y / viewSize.y };
	auto pos = target->getPosition();
	position.x = pos.x - 100;
	renderer->setOffset(position);
	renderer->setScale(scale);
}

