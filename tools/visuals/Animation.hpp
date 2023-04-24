#pragma once

#include "../../Game.hpp"
#include "Sprite.hpp"

class Animation : public Sprite
{
public:
    Animation();
    Animation(const char* file, int x, int y, double angle, int frames, int speed, int srcWhichAnimation);
    ~Animation();

    void drawAnimation();

    void setFrames(int value);
    void setSpeed(int value);
    void setSrcWhichAnimation(int value);
    void setActiveTrue();
    void setActiveFalse();

protected:
    int animationFrames, animationSpeed;
    int srcWhichAnimation;
    bool isActive{true};
};