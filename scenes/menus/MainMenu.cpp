#include "MainMenu.hpp"

MainMenu::MainMenu()
: Menu()
{
    this->setOptions();
}

MainMenu::MainMenu(SDL_Color bgColor, SDL_Color textColor)
: Menu(bgColor, textColor)
{
    this->setOptions();
    
}

MainMenu::~MainMenu()
{
    for(auto button : this->options){
        delete button;
    }
}

void MainMenu::update()
{
    this->handleEvents();
    this->action();
}

void MainMenu::render()
{
    SDL_SetRenderDrawColor(Game::Renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
    for(auto button : this->options){
        button->draw();
    }
    this->selectButton();
}

void MainMenu::setOptions()
{
    this->options.push_back(new Button("assets/fonts/retroGaming.ttf", "New Game", BUTTONPOS_CENTERED_WIDTH, 0, 500, 32, SDL_Color{0,0,255,0}));
    this->options.push_back(new Button("assets/fonts/retroGaming.ttf", "Continue", BUTTONPOS_CENTERED_WIDTH, 0, 550, 32, SDL_Color{0,0,255,0}));
    this->options.push_back(new Button("assets/fonts/retroGaming.ttf", "Settings", BUTTONPOS_CENTERED_WIDTH, 0, 600, 32, SDL_Color{0,0,255,0}));
    this->options.push_back(new Button("assets/fonts/retroGaming.ttf", "Credits", BUTTONPOS_CENTERED_WIDTH, 0, 650, 32, SDL_Color{0,0,255,0}));
    this->options.push_back(new Button("assets/fonts/retroGaming.ttf", "Quit", BUTTONPOS_CENTERED_WIDTH, 0, 700, 32, SDL_Color{0,0,255,0}));
}

void MainMenu::action()
{
    if(Game::Event.type == SDL_KEYDOWN)
    {
        if(Game::Event.key.keysym.sym == SDLK_e)
        {
            switch(this->indexButton)
            {
                case 0: Game::currentScene = SCENE_MAINGAME; break;
                case 1: Game::currentScene = SCENE_MAINGAME; break;
                case 2: Game::currentScene = SCENE_SETTINGS; break;
                case 3: Game::currentScene = SCENE_CREDITS; break;
                case 4: Game::gameRunning = false; break;
            }
        }
    }


}