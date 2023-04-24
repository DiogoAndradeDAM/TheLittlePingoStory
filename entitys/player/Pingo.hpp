#pragma once

#include "../../Game.hpp"
#include "../Entity.hpp"

class Pingo : public Entity
{
public:
    Pingo();
    Pingo(const char* file, int x, int y, double angle, int frames, int speed, int srcWhichAnimation);
    ~Pingo();

    void update() override;
private:
    void handleInputs();

};