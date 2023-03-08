#ifndef TEXTBASED_SPRITECOMPONENT_H
#define TEXTBASED_SPRITECOMPONENT_H
#include <string>
#include <utility>
#include "../../Globals.h"

struct SpriteComponent {
    WindowNum renderWidth;
    WindowNum renderHeight;
    std::string text;

    explicit SpriteComponent(std::string text){
        this->text = text;
        this->renderWidth = text.size() * RENDERED_TEXT_WIDTH_SCALER;
        this->renderHeight = RENDERED_TEXT_HEIGHT;
    }

    explicit SpriteComponent(std::string text, WindowNum width, WindowNum height ){
        this->text = text;
        this->renderWidth = text.size() * RENDERED_TEXT_WIDTH_SCALER;
        this->renderHeight = height;
    }

    SpriteComponent() {
        this->text = "Robert C. Martin";
        this->renderWidth = text.size() * RENDERED_TEXT_WIDTH_SCALER;
        this->renderHeight = RENDERED_TEXT_HEIGHT;
    }

};


#endif //TEXTBASED_SPRITECOMPONENT_H
