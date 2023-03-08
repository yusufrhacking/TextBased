#ifndef TEXTBASED_SPRITECOMPONENT_H
#define TEXTBASED_SPRITECOMPONENT_H
#include <string>
#include <utility>
#include "../../Globals.h"

struct SpriteComponent {
    Size width;
    Size height;
    std::string text;

    explicit SpriteComponent(std::string text){
        this->text = text;
        this->width = text.size() * RENDERED_TEXT_WIDTH_SCALER;
        this->height = RENDERED_TEXT_HEIGHT;
    }

    explicit SpriteComponent(std::string text, Size width, Size height ){
        this->text = text;
        this->width = text.size() * RENDERED_TEXT_WIDTH_SCALER;
        this->height = height;
    }

    SpriteComponent() {
        this->text = "Robert C. Martin";
        this->width = text.size() * RENDERED_TEXT_WIDTH_SCALER;
        this->height = RENDERED_TEXT_HEIGHT;
    }

};


#endif //TEXTBASED_SPRITECOMPONENT_H
