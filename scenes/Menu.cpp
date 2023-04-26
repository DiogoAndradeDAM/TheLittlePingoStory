#include "Menu.hpp"
#include "../tools/TextureManager.hpp"
#include "../tools/Vector2.hpp"

Menu::Menu()
:Scene()
{
    this->indexButton = 0;
}

Menu::Menu(SDL_Color bgColor, SDL_Color textColor)
:Scene(bgColor), textColor(textColor)
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
            case SDLK_UP: this->indexButton += ((this->indexButton <= 0) ? 0 : -1); break;
            case SDLK_DOWN: this->indexButton += ((this->indexButton >= this->options.size()-1) ? 0 : 1); break;
        }
    }
}

void Menu::selectButton()
{
    Vector2 vec = this->options.at(this->indexButton)->getPosition();
    int width=0, height=0;
    SDL_QueryTexture(this->options.at(this->indexButton)->getTexture(), NULL, NULL, &width, &height);

    SDL_Rect selectionRect1{vec.x-50, vec.y+12, 32,8};
    SDL_Rect selectionRect2{(vec.x+width)+30, vec.y+12, 32,8};

    SDL_SetRenderDrawColor(Game::Renderer, this->textColor.r, this->textColor.g, this->textColor.b, this->textColor.a);
    SDL_RenderFillRect(Game::Renderer, &selectionRect1);
    SDL_RenderFillRect(Game::Renderer, &selectionRect2);
    SDL_SetRenderDrawColor(Game::Renderer, this->bgColor.r, this->bgColor.g, this->bgColor.b, this->bgColor.a);
}