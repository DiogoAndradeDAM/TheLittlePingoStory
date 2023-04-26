#include "Menu.hpp"
#include "../tools/TextureManager.hpp"
#include "../tools/Vector2.hpp"

Menu::Menu()
:Scene()
{
    this->indexButton = 0;
}

Menu::Menu(SDL_Color bgColor)
:Scene(bgColor)
{
    this->indexButton = 0;

}

Menu::~Menu()
{

}

void Menu::handleEvents()
{
    if(Game::Event.type == SDL_KEYDOWN)
    {
        switch(Game::Event.key.keysym.sym)
        {
            case SDLK_UP: this->indexButton += ((this->indexButton >= this->options.size()) ? 0 : -1); break;
            case SDLK_DOWN: this->indexButton += ((this->indexButton <= 0) ? 0 : 1); break;
        }
    }
}

void Menu::selectButton()
{
    Vector2 vec = this->options.at(this->indexButton)->getPosition();
    int width=0, height=0;
    SDL_QueryTexture(this->options.at(this->indexButton)->getTexture(), NULL, NULL, &width, &height);

    SDL_Rect selectionRect{vec.x-20, vec.y+(height/2), 16,16};

    SDL_SetRenderDrawColor(Game::Renderer, 0, 0, 255, 0);
    SDL_RenderFillRect(Game::Renderer, &selectionRect);
    SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 0);
}