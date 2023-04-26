#pragma once 

#include "../Game.hpp"
#include "Scene.hpp"
#include "../tools/Vector2.hpp"


class MainGame : public Scene
{
public:
    MainGame();
    MainGame(SDL_Color bgColor, Vector2 playerPosition);
    ~MainGame();

    void update() override;
    void render() override;
private:
    void handleEvents() override;

};