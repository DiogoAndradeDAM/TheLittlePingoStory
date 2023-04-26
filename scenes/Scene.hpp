#pragma once

#include "../Game.hpp"

class Scene
{
public:
    Scene();
    Scene(SDL_Color bgColor);
    ~Scene();
    virtual void update()=0;
    virtual void render()=0;
protected:
    SDL_Color bgColor;
    virtual void handleEvents()=0;

};