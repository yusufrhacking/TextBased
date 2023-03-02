#ifndef TEXTBASED_SPRITECOMPONENT_H
#define TEXTBASED_SPRITECOMPONENT_H
#include <string>
#include <utility>

using Size = unsigned int;

const Size DEFAULT_WIDTH = 10;
const Size DEFAULT_HEIGHT = 10;

struct SpriteComponent {
    Size width = DEFAULT_WIDTH;
    Size height = DEFAULT_HEIGHT;
    const char *text;

    explicit SpriteComponent(std::string text){
        this->text = std::move(text);
    }

    explicit SpriteComponent(std::string text, Size width, Size height ){
        this->text = std::move(text);
        this->width = width;
        this->height = height;
    }

};


#endif //TEXTBASED_SPRITECOMPONENT_H
