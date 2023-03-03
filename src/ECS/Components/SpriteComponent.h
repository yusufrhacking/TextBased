#ifndef TEXTBASED_SPRITECOMPONENT_H
#define TEXTBASED_SPRITECOMPONENT_H
#include <string>
#include <utility>

using Size = unsigned int;

const Size DEFAULT_WIDTH_SCALER = 6;
const Size DEFAULT_HEIGHT = 11;

struct SpriteComponent {
    Size width;
    Size height;
    std::string text;

    explicit SpriteComponent(std::string text){
        this->text = text;
        this->width = text.size() * DEFAULT_WIDTH_SCALER;
        this->height = DEFAULT_HEIGHT;
    }

    explicit SpriteComponent(std::string text, Size width, Size height ){
        this->text = text;
        this->width = text.size() * DEFAULT_WIDTH_SCALER;
        this->height = height;
    }

    SpriteComponent() {
        this->text = "Robert C. Martin";
        this->width = text.size() * DEFAULT_WIDTH_SCALER;
        this->height = DEFAULT_HEIGHT;
    }

};


#endif //TEXTBASED_SPRITECOMPONENT_H
