#include "Game.hpp"
#include "tools/visuals/Animation.hpp"
#include "entitys/player/Pingo.hpp"
#include "scenes/menus/MainMenu.hpp"

SDL_Window* window = nullptr;
SDL_Renderer* Game::Renderer = nullptr;
SDL_Event Game::Event;
int Game::Fps;

Pingo* pingo = nullptr;
MainMenu* menu = nullptr;

Game::Game(const char* title, int x, int y, int width, int height, int fps)
: x(x), y(y), width(width), height(height)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        this->window = SDL_CreateWindow(title, this->x, this->y, this->width, this->height, 0);
        if(this->window == NULL) std::cout << "Failed init Window. Error: " << SDL_GetError() << std::endl;

        Game::Renderer = SDL_CreateRenderer(this->window, -1, 0);
        if(Game::Renderer == NULL) std::cout << "Failed init Renderer. Error: " << SDL_GetError() << std::endl;
        SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 0);

        if(TTF_Init() == -1) std::cout << "Failed to init TTF. Error: " << SDL_GetError() << std::endl;

        Game::Fps = fps;

        pingo = new Pingo("assets/images/pingoSpriteSheet_move.png", 200, 200, 0.f, 4, 100, 0);
        menu = new MainMenu(SDL_Color{255,255,255,0});


        this->gameRunning = true;
    }else{
        this->gameRunning = false;
    }
}

Game::~Game()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(Game::Renderer);
    TTF_Quit();
    SDL_Quit();
}

void Game::handleEvent()
{
    SDL_PollEvent(&Game::Event);
    
    switch(Game::Event.type)
    {
        case SDL_QUIT: this->gameRunning = false; break;    
        default: break;
    }

}

void Game::update()
{
    pingo->update();
    menu->update();
}

void Game::render()
{
    SDL_RenderClear(Game::Renderer);

    pingo->drawAnimation();
    menu->render();

    SDL_RenderPresent(Game::Renderer);
}

void Game::setFPS(Uint8 frameStart)
{
    const int FRAME_DELAY = 1000/Game::Fps;
    int frameTime = SDL_GetTicks() - frameStart;
    if(FRAME_DELAY > frameTime){
        SDL_Delay(FRAME_DELAY - frameTime);
    }
}

void Game::run()
{
    Uint8 ticks = 0;
    while(this->isRunning())
    {
        ticks = SDL_GetTicks();
        this->handleEvent();
        this->update();
        this->render();
        this->setFPS(ticks);
    }
}