#pragma once

#include "../Game.hpp"
#include "Scene.hpp"
#include "../tools/visuals/Button.hpp"

#include <vector>

class Menu : public Scene
{
public:
    Menu();
    Menu(SDL_Color bgColor);
    ~Menu();

protected:
    std::vector<Button*> options;
    virtual void setOptions()=0;
    void handleEvents();//Movimenta o indice
    void selectButton();//Baseado no indice, mostra qual botão está selecionado no momento
    virtual void action()=0;//Baseado no indicem chama a funcionalidade dos botões
    int indexButton;
};