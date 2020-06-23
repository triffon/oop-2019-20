#include <stdio.h>
#include <thread>
#include <chrono>
#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"

int main(int argc, char** argv)
{

    Game game;
    game.init();
    game.setupGame();
    game.gameLoop();
    ////SDL_DestroyTexture(texture);
    ////SDL_FreeSurface(image);
    ////SDL_DestroyRenderer(renderer);
    ////SDL_DestroyWindow(window);

    //SDL_Quit();

    return 0;
}