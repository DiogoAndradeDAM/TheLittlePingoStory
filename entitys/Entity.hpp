#pragma once

#include "../Game.hpp"
#include "../tools/visuals/Animation.hpp"

class Entity: public Animation
{
public:
    Entity();
    Entity(const char* File, int x, int y, double angle, int frames, int speed, int srcWhichAnimation);
    ~Entity();

    virtual void update() = 0;

protected:
    void clamp();
};