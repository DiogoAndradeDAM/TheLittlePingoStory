#include "TextureManager.hpp"
#include "../Game.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* filePath)
{
    SDL_Texture* texture = IMG_LoadTexture(Game::Renderer, filePath);
    if(texture == NULL) std::cout << "Failed to init texture. Error: " << SDL_GetError() << std::endl;

    return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::Renderer, texture, &src, &dest);
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, double angle)
{
    SDL_RenderCopyEx(Game::Renderer, texture, &src, &dest, angle, NULL, SDL_FLIP_NONE);
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, double angle, SDL_Point* point)
{
    SDL_RenderCopyEx(Game::Renderer, texture, &src, &dest, angle, point, SDL_FLIP_NONE);
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, double angle, SDL_Point* point, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(Game::Renderer, texture, &src, &dest, angle, point, flip);
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, double angle, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(Game::Renderer, texture, &src, &dest, angle, NULL, flip);
}

SDL_Texture* TextureManager::LoadText(const char* file, const char* text, int fontSize, SDL_Color color)
{
    TTF_Font* font = TTF_OpenFont(file, fontSize);
    SDL_Surface* tmpSurface = TTF_RenderText_Solid(font, text, color);
    if(tmpSurface == NULL) std::cout << "Failed to load font to Surface. Error: " << TTF_GetError() << std::endl;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::Renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    
    return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect dest)
{
    SDL_RenderCopy(Game::Renderer, texture, NULL, &dest);
}