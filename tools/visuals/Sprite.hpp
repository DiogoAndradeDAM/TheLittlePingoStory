#pragma once

#include "../../Game.hpp"
#include "../Vector2.hpp"

class Sprite
{
public:
    Sprite(const char* texture, int x, int y, double angle);
    Sprite();
    ~Sprite();
    void draw();
    void setRect(SDL_Rect* rect, int x, int y, int w, int h);
    Vector2 getPosition(){return vec;}
    void setPosition(int x, int y);
    void setTexture(const char* file);
    void setPosInSrc(int x, int y);
    void move(int x, int y);
    void flipW();
    void flipNone();
    SDL_Texture* getTexture(){return this->texture;}
protected:
    Vector2 vec;
    int wsrc=16, hsrc=16, wdest, hdest;
    SDL_Texture* texture;
    SDL_Rect src, dest;
    double angle;
    SDL_RendererFlip flip;
};