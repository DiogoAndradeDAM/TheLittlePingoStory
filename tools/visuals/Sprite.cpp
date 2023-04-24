#include "Sprite.hpp"
#include "../TextureManager.hpp"

Sprite::Sprite(const char* texture, int x, int y, double angle)
: angle(angle)
{
    this->texture = TextureManager::LoadTexture(texture);
    this->vec.x = x;
    this->vec.y = y;

    this->wdest = this->wsrc*4;
    this->hdest = this->hsrc*4;

    this->setRect(&this->src, 0, 0, this->wsrc, this->hsrc);
    this->setRect(&this->dest, this->vec.x, this->vec.y, this->wdest, this->hdest);
    this->flip = SDL_FLIP_NONE;
}

Sprite::Sprite()
{
    this->texture = NULL;
    this->vec.x = 0;
    this->vec.y = 0;
    this->angle = 0.f;
    this->flip = SDL_FLIP_NONE;
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
}

void Sprite::draw()
{
    this->setRect(&this->dest, this->vec.x, this->vec.y, this->wdest, this->hdest);
    TextureManager::Draw(this->texture, this->src, this->dest);
}

void Sprite::setTexture(const char* file)
{
    this->texture = TextureManager::LoadTexture(file);
}

void Sprite::setPosInSrc(int x=0, int y=0)
{
    this->setRect(&this->src, x, y, this->wsrc, this->hsrc);
}

void Sprite::setPosition(int x=0, int y=0)
{
    this->vec.x = x;
    this->vec.y = y;
}

void Sprite::move(int x=0, int y=0)
{
    this->vec.x += x;
    this->vec.y += y;
}

void Sprite::setRect(SDL_Rect* rect, int x, int y, int w, int h)
{
    rect->x = x;
    rect->y = y;
    rect->h = h;
    rect->w = w;
}

void Sprite::flipNone()
{
    this->flip = SDL_FLIP_NONE;
}

void Sprite::flipW()
{
    this->flip = SDL_FLIP_HORIZONTAL;
}