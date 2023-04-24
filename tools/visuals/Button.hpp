#pragma once

#include "../../Game.hpp"
#include "../Vector2.hpp"
#include "Sprite.hpp"

enum EButtonPosition
{
    BUTTONPOS_NONE,
    BUTTONPOS_CENTERED,
    BUTTONPOS_CENTERED_WIDTH,
    BUTTONPOS_CENTERED_HEIGHT,
};

class Button : public Sprite
{
public:
    Button();
    Button(const char* file, const char* text, EButtonPosition buttonPosition, int x, int y, int fontSize, SDL_Color color);
    ~Button();

    void draw();
    void update();
    void modSelection();

private:
TTF_Font* font;
int fontSize;
const char* text;
const char* file;
SDL_Color textColor;
bool isSelected {false};

};