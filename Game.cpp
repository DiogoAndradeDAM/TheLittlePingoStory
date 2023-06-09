#include "Game.hpp"
#include "tools/visuals/Animation.hpp"
#include "scenes/MainGame.hpp"
#include "scenes/menus/MainMenu.hpp"
#include "tools/Vector2.hpp"

SDL_Window* window = nullptr;
SDL_Renderer* Game::Renderer = nullptr;
SDL_Event Game::Event;
int Game::Fps;
bool Game::gameRunning;

MainMenu* mainMenu = nullptr;
MainGame* mainGame = nullptr;
EScenes Game::currentScene = SCENE_NONE;

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

        Vector2 vec1{200, 200};
        Vector2 vec2{900, 350};

        mainMenu = new MainMenu(SDL_Color{255,255,255,0}, SDL_Color{0,0,255,0});
        mainGame = new MainGame(SDL_Color{255,255,255,0}, vec1);

        Game::currentScene = SCENE_MAINMENU;

        Game::gameRunning = true;
    }else{
        Game::gameRunning = false;
    }
}

Game::~Game()
{
    delete mainMenu;

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
        case SDL_QUIT: Game::gameRunning = false; break;    
        default: break;
    }

}

void Game::update()
{
    if(Game::currentScene == SCENE_MAINMENU)
    {
        mainMenu->update();
    }
    else if(Game::currentScene == SCENE_MAINGAME)
    {
        mainGame->update();
    }
}

void Game::render()
{
    SDL_RenderClear(Game::Renderer);

    if(Game::currentScene == SCENE_MAINMENU)
    {
        mainMenu->render();
    }
    else if(Game::currentScene == SCENE_MAINGAME)
    {
        mainGame->render();
    }

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