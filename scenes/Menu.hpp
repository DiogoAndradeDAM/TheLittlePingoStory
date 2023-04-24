#pragma once

#include "../Game.hpp"
#include "Scene.hpp"
#include "../tools/visuals/Button.hpp"

#include <vector>

class Menu : public Scene
{
public:
    Menu();
    Menu(SDL_Color bgColor);
    ~Menu();

protected:
    std::vector<Button*> options;
    virtual void setOptions()=0;
};