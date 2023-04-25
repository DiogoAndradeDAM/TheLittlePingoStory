#pragma once

#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <SDL2\SDL_ttf.h>
#include <iostream>

enum EScenes
{
    SCENE_NONE,
    SCENE_MAINMENU,
    SCENE_MAINGAME,
};

class Game
{
    public:
    Game(const char* title, int x, int y, int width, int height, int fps);
    ~Game();

    void handleEvent();
    void update();
    void render();
    void run();
    void setFPS(Uint8 frameStart);

    bool isRunning(){return this->gameRunning;}

    static SDL_Renderer* Renderer;
    static int Fps;
    static SDL_Event Event;
    static EScenes currentScene;
    private:

    SDL_Window* window;
    int x, y, width, height;
    bool gameRunning;

};