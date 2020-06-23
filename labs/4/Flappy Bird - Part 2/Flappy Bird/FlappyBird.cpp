#include "FlappyBird.h"
#include "Game.h"
#include "Input.h"
#include "Renderer.h"

FlappyBird::FlappyBird() : GameObject({ 0,0 }), accelration(0), sideSpeed(2.f)
{
	
}

void FlappyBird::init(Game* game)
{
	auto renderer = game->getRenderer();
	auto texture = renderer->createTexture("image.jpg");
	model.setTexutre(texture);
	model.setPosition(position);
	model.setSize({ 200, 200 });
}

void FlappyBird::update(Game* game)
{
	auto input = game->getInput();
	accelration += 1.f;
	if (input->isKeyPressed(SDL_KeyCode::SDLK_SPACE)) {
		accelration = -20.f;
	}

	position.operator+=({ sideSpeed, accelration });
	model.setPosition(position);
}

void FlappyBird::render(Renderer* renderer)
{
	renderer->renderModel(&model);
}
