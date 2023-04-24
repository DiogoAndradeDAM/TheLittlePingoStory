#pragma once

#include "../../Game.hpp"
#include "../Menu.hpp"

class MainMenu : public Menu
{
public:
    MainMenu();
    MainMenu(SDL_Color bgColor);
    ~MainMenu();

    void update() override;
    void render() override;
private:
    void setOptions() override;
};