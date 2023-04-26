#pragma once

#include "../Game.hpp"
#include "Scene.hpp"
#include "../tools/visuals/Button.hpp"

#include <vector>

class Menu : public Scene
{
public:
    Menu();
    Menu(SDL_Color bgColor, SDL_Color textColor);
    ~Menu();


protected:
    std::vector<Button*> options;
    virtual void setOptions()=0;
    virtual void action()=0;//Baseado no indicem chama a funcionalidade dos botões
    void handleEvents();//Movimenta o indice
    void selectButton();//Baseado no indice, mostra qual botão está selecionado no momento
    int indexButton;
    SDL_Color textColor;
};