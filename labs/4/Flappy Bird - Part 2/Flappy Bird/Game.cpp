#include <thread>
#include <chrono>
#include "Game.h"
#include "Renderer.h"
#include "Input.h"
#include "Camera.h"
#include "Model.h"
#include "FlappyBird.h"
#include "PipeSpawner.h"

Game::Game()
	: renderer(std::make_shared<Renderer>()),
	input(std::make_shared<Input>()),
    camera(std::make_shared<Camera>(renderer.get()))
{
}

void Game::init()
{
	renderer->createWindow();
	renderer->init();
}

void Game::setupGame()
{
    player = std::make_shared<FlappyBird>();
    player->init(this);
    camera->setTarget(player.get());
    pipeSpawner = std::make_shared<PipeSpawner>();
    pipeSpawner->init(this);

    gameObjects.push_back(player);
    gameObjects.push_back(pipeSpawner);
}

void Game::updateGameObjects() {
    input->update();
    camera->update();

    for (auto& object : gameObjects) {
        object->update(this);
    }
}

void Game::renderGameObjects() {
    for (auto& object : gameObjects) {
        object->render(renderer.get());
    }
    renderer->present();
}

void Game::gameLoop()
{
    while (true) {
        renderer->clear();
        input->update();
        if (input->hasExitEvent()) {
            break;
        }
        updateGameObjects();
        renderGameObjects();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}

void Game::destroy()
{
}
