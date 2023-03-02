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
    std::string text;

    explicit SpriteComponent(std::string text){
        this->text = std::move(text);
    }

    explicit SpriteComponent(std::string text, Size width, Size height ){
        this->text = std::move(text);
        this->width = width;
        this->height = height;
    }

    SpriteComponent() {
        this->text = "Robert C. Martin";
    }

};


#endif //TEXTBASED_SPRITECOMPONENT_H
