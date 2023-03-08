#ifndef TEXTBASED_SPRITECOMPONENT_H
#define TEXTBASED_SPRITECOMPONENT_H
#include <string>
#include <utility>
#include "../../Globals.h"
#include "../../Objects/Size.h"
#include <sstream>

struct SpriteComponent {
    Size surfaceSize;
    std::string text;

    explicit SpriteComponent(std::string text){
        this->text = text;
        surfaceSize = {static_cast<WindowNum>(getTextWidth() * RENDERED_TEXT_WIDTH_SCALER), RENDERED_TEXT_HEIGHT * getTextHeight()};
    }

    SpriteComponent() {
        this->text = "Robert C. Martin";
        surfaceSize = {static_cast<WindowNum>(getTextWidth() * RENDERED_TEXT_WIDTH_SCALER), RENDERED_TEXT_HEIGHT};
    }

private:
    int getTextHeight() const {
        int height = 0;
        std::istringstream textStream(text);
        std::string token;
        while(std::getline(textStream, token, '\n')) {
            height++;
        }
        return height;
    }

    unsigned int getTextWidth() const {
        unsigned int longestWidth = 0;
        std::istringstream textStream(text);
        std::string token;
        while(std::getline(textStream, token, '\n')) {
            if (token.size() > longestWidth){
                longestWidth = token.size();
            }
        }
        return longestWidth;
    }
};


#endif //TEXTBASED_SPRITECOMPONENT_H
