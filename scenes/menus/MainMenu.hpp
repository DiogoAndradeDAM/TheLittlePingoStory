#pragma once

#include "../../Game.hpp"
#include "../Menu.hpp"
#include "../Scene.hpp"

class MainMenu : public Menu
{
public:
    MainMenu();
    MainMenu(SDL_Color bgColor, SDL_Color textColor);
    ~MainMenu();

    void update() override;
    void render() override;
private:
    void action() override;
    void setOptions() override;
};