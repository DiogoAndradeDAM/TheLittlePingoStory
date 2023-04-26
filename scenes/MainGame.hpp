#pragma once 

#include "../Game.hpp"
#include "Scene.hpp"

class MainGame : public Scene
{
public:
    MainGame();
    MainGame(SDL_Color bgColor);
    ~MainGame();

    void update() override;
    void render() override;
private:
    void handleEvents() override;

};