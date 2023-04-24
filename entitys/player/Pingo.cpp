#include "Pingo.hpp"

Pingo::Pingo()
:Entity()
{

}

Pingo::Pingo(const char* file, int x, int y, double angle, int frames, int speed, int srcWhichAnimation)
:Entity(file, x, y, angle, frames, speed, srcWhichAnimation)
{

}

Pingo::~Pingo()
{
    SDL_DestroyTexture(this->texture);
}

void Pingo::update()
{
    this->handleInputs();
    this->clamp();
}

void Pingo::handleInputs()
{
    if(Game::Event.type == SDL_KEYDOWN)
    {
        switch(Game::Event.key.keysym.sym) 
        {
        case SDLK_d: 
            this->move(10,0); 
            this->setSrcWhichAnimation(32);
            this->flipNone();
            this->setActiveTrue();
        break;
        case SDLK_a: 
            this->setSrcWhichAnimation(32);
            this->move(-10,0);
            this->flipW();
            this->setActiveTrue(); 
        break;
        case SDLK_s: 
            this->setSrcWhichAnimation(0);
            this->move(0,10); 
            this->flipNone();
            this->setActiveTrue();
        break;
        case SDLK_w: 
            this->setSrcWhichAnimation(16);
            this->move(0,-10);
            this->flipNone();
            this->setActiveTrue(); 
        break;
        }
    }else if(Game::Event.type == SDL_KEYUP){
         this->setActiveFalse();
    }
}