#pragma once
#include <memory>
#include <vector>
#include "GameObject.h"

class Renderer;
class Input;
class Camera;
class FlappyBird;
class PipeSpawner;

class Game
{
	std::shared_ptr<Renderer> renderer;
	std::shared_ptr<Input> input;
	std::shared_ptr<Camera> camera;

	std::vector<std::shared_ptr<GameObject>> gameObjects;

	std::shared_ptr<FlappyBird> player;
	std::shared_ptr<PipeSpawner> pipeSpawner;

	void updateGameObjects();
	void renderGameObjects();

public:
	Game();
	void init();
	void setupGame();
	void gameLoop();
	void destroy();


	std::shared_ptr<Camera> getCamera() { return camera; }
	std::shared_ptr<Input> getInput() { return input; }
	std::shared_ptr<Renderer> getRenderer() { return renderer; }
};

