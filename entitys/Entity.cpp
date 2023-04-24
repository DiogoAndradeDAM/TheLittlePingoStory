#include "Entity.hpp"
#include "../tools/TextureManager.hpp"


Entity::Entity(const char* file, int x, int y, double angle, int frames, int speed, int srcWhichAnimation)
:Animation(file, x, y, angle, frames, speed, srcWhichAnimation)
{

}

Entity::Entity()
: Animation()
{

}

Entity::~Entity()
{
    SDL_DestroyTexture(this->texture);
}

void Entity::clamp()
{
    if(this->vec.x + this->wdest > 1024){
        this->vec.x = 1024 - this->wdest;
    }else if(this->vec.x < 0){
        this->vec.x = 0;
    }
}

