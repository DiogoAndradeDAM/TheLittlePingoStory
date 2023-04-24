#include "Scene.hpp"

Scene::Scene()
{
    this->bgColor = {0,0,0,0};
}

Scene::Scene(SDL_Color bgColor)
:bgColor(bgColor)
{

}

Scene::~Scene()
{

}