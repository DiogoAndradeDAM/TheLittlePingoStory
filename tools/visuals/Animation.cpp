#include "Animation.hpp"
#include "../TextureManager.hpp"

Animation::Animation()
: animationFrames(0), animationSpeed(0), isActive(false)
{
    this->texture = nullptr;
    this->vec.x = 0; 
    this->vec.y = 0;
}

Animation::Animation(const char* file, int x, int y, double angle, int frames, int speed, int srcWhichAnimation)
: Sprite(file, x, y, angle), animationFrames(frames), animationSpeed(speed), isActive(false), srcWhichAnimation(srcWhichAnimation)
{

}

Animation::~Animation()
{
    SDL_DestroyTexture(this->texture);
}

void Animation::drawAnimation()
{
    if(this->isActive){
        int index = (int) ((SDL_GetTicks() / this->animationSpeed) % this->animationFrames);
        this->setRect(&this->src, index*16, this->srcWhichAnimation, 16, 16);
    }
    this->setRect(&this->dest, this->vec.x, this->vec.y, this->wdest, this->hdest);
    TextureManager::Draw(this->texture, this->src, this->dest, this->angle, this->flip);
}

void Animation::setActiveTrue()
{
    this->isActive = true; 
}

void Animation::setActiveFalse()
{
    this->isActive = false; 
}


void Animation::setFrames(int value)
{
    this->animationFrames = value;
}

void Animation::setSpeed(int value)
{
    this->animationSpeed = value;
}

void Animation::setSrcWhichAnimation(int value)
{
    this->srcWhichAnimation = value;
}