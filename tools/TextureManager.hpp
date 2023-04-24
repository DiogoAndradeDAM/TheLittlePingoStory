#pragma once

#include "../Game.hpp"

class TextureManager
{
public:
    static SDL_Texture* LoadTexture(const char* filePath);
    
    static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
    static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, double angle);
    static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, double angle, SDL_Point* point);
    static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, double angle, SDL_Point* point, SDL_RendererFlip flip);
    static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, double angle, SDL_RendererFlip flip);

    static SDL_Texture* LoadText(const char* file, const char* text, int fontSize, SDL_Color color);
    static void Draw(SDL_Texture* texture, SDL_Rect dest);
};