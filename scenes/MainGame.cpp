#include "MainGame.hpp"
#include "../entitys/player/Pingo.hpp"

Pingo *pingo = nullptr;

MainGame::MainGame()
:Scene()
{
    pingo = new Pingo("assets/images/pingoSpriteSheet_move.png", 200, 200, 0.f, 4, 100, 0);
    
}

MainGame::MainGame(SDL_Color bgColor)
:Scene(bgColor)
{
    pingo = new Pingo("assets/images/pingoSpriteSheet_move.png", 200, 200, 0.f, 4, 100, 0);

}

MainGame::~MainGame()
{
    delete pingo;
}

void MainGame::update()
{
    this->handleEvents();
    
    pingo->update();
}

void MainGame::render()
{
    pingo->drawAnimation();
}

void MainGame::handleEvents()
{

}