#include "Button.hpp"
#include "../TextureManager.hpp"

Button::Button()
{
    this->texture = nullptr;
    this->text = "none";
    this->hdest = this->wdest = 0;
    this->font = nullptr;
}

Button::Button(const char* file, const char* text, EButtonPosition buttonPosition, int x, int y, int fontSize, SDL_Color color)
: file(file), text(text), fontSize(fontSize), textColor(color)
{
    this->texture = TextureManager::LoadText(this->file, this->text, this->fontSize, this->textColor);

    this->vec.x = x;
    this->vec.y = y;

    SDL_QueryTexture(this->texture, NULL, NULL, &this->wdest, &this->hdest);

    this->dest.w = this->wdest;
    this->dest.h = this->hdest;

    switch(buttonPosition)
    {
        case BUTTONPOS_CENTERED:
            this->dest.x = 512 - (this->wdest/2);
            this->dest.y = 384 - (this->hdest/2);
            this->vec.x = this->dest.x;
            this->vec.y = this->dest.y;
            break;
        case BUTTONPOS_CENTERED_WIDTH:
            this->dest.x = 512 - (this->wdest/2);
            this->dest.y = this->vec.y;
            this->vec.x = this->dest.x;
            break;
        case BUTTONPOS_CENTERED_HEIGHT:
            this->dest.x = this->vec.x;
            this->dest.y = 384 - (this->hdest/2);
            this->vec.y = this->dest.y;
            break;

        default:    
            this->dest.x = this->vec.x;
            this->dest.y = this->vec.y;
            break;
    }
    

}

void Button::modSelection()
{
    this->isSelected = ((!this->isSelected) ? true : false );
}

Button::~Button()
{
    SDL_DestroyTexture(this->texture);
}

void Button::draw()
{
    TextureManager::Draw(this->texture, this->dest);
}

void Button::update()
{
    if(this->isSelected){
        this->texture = TextureManager::LoadText(this->file, this->text, this->fontSize, SDL_Color{255,0,0,0});
    }else{
        this->texture = TextureManager::LoadText(this->file, this->text, this->fontSize, this->textColor);
    }
}