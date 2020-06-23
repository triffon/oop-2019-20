#include <iostream>
#include "SDL.h"
#include "Input.h"
using namespace std;

Input::Input() : exitEventReceived(false)
{
    keys.resize(300, false);
}

void Input::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            keys[event.key.keysym.sym] = true;
            break;
        case SDL_KEYUP:
            keys[event.key.keysym.sym] = false;
            break;
        case SDL_QUIT:
            exitEventReceived = true;
            break;
        }

    }
}

bool Input::isKeyPressed(SDL_KeyCode code)
{
    return keys[code];
}

bool Input::hasExitEvent()
{
    return exitEventReceived;
}
