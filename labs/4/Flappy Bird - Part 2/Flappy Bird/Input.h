#pragma once
#include <vector>
#include "SDL.h"

class Input
{
	std::vector<bool> keys;
	bool exitEventReceived;
public:
	Input();
	void update();
	bool isKeyPressed(SDL_KeyCode code);
	bool hasExitEvent();
};

