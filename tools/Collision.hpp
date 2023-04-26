#pragma once

#include "../Game.hpp"
#include "../entitys/Entity.hpp"
#include "../entitys/player/Pingo.hpp"

enum ECollisionTypes
{
    COLLISION_NONE,
    COLLISION_ALL,
    COLLISION_PLAYER,
    COLLISION_ENEMY,
    COLLISION_COLLECTABLE,
};

//O que devo fazer? Um enumerador que analisa o que está colidindo e fazer a checagem dentro das classes ou criar uma manejador de colisões que detecta para as classes?

class CollisionManager
{
public:
    static bool checkCollision();
};