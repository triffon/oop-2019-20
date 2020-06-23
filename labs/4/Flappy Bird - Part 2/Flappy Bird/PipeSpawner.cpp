#include "SDL.h"
#include "PipeSpawner.h"
#include "Game.h"
#include "Camera.h"

PipeSpawner::PipeSpawner(): GameObject({0,0}), pipeHDistance(200), pipeVDistance(200)
{
}

void PipeSpawner::update(Game* game)
{
	size_t pipesLen = pipes.size();
	auto camera = game->getCamera();
	Vec2D cameraPos = camera->getPosition();
	Vec2D cameraSize = camera->getSize();
	Vec2D cameraScale = camera->getScale();

	for (int idx = 0; idx < pipesLen; ++idx) {
		if (pipes[idx].x + 200 < cameraPos.x) //@TODO remove hardcode
		{
			Vec2D currentPipe = pipes[idx];
			pipes.erase(pipes.begin() + idx);
			currentPipe.x = cameraPos.x + cameraSize.x * cameraScale.x;
			pipes.push_back(currentPipe);
		}
	}
}

void PipeSpawner::render(Renderer* renderer)
{
	size_t pipesLen = pipes.size();
	Vec2D offset = renderer->getOffset();
	for (int idx = 0; idx < pipesLen; ++idx) {
		renderer->drawRect({ (int)(pipes[idx].x), (int)(pipes[idx].y) , 100, 200 });
	}
}

void PipeSpawner::init(Game* game)
{
	auto camera = game->getCamera();
	auto cameraSize = camera->getSize();
	auto cameraPosition = camera->getPosition();

	int numPipes = (int)(cameraSize.x / pipeHDistance);
	float cameraEnd = cameraPosition.x + cameraSize.x;
	for (int idx = 0; idx < numPipes; ++idx) {
		pipes.push_back({ cameraEnd + pipeHDistance * idx, 0 });
		pipes.push_back({ cameraEnd + pipeHDistance * idx, cameraSize.y - 200 });
	}

}
