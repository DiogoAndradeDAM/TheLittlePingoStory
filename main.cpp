#include <SDL2\SDL.h>
#include <iostream>

#include "Game.hpp"

const int WINDOW_WIDTH = 960, WINDOW_HEIGHT = 768;
const int FPS = 60;

Game* game = nullptr;

int main(int argc, char** argv)
{
    game = new Game(
        "The Little Pingo Story",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        FPS
    );

    game->run();

    delete game;

    return 0;
}