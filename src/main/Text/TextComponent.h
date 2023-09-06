#ifndef TEXTBASED_TEXTCOMPONENT_H
#define TEXTBASED_TEXTCOMPONENT_H
#include <string>
#include <utility>
#include "../HighLevel/Globals.h"
#include "../PositionsAndMovement/Size.h"
#include <sstream>

struct TextComponent {
    Size surfaceSize;
    std::string text;

    explicit TextComponent(std::string text){
        this->text = text;
        surfaceSize = {static_cast<RenderedVal>(getTextWidth() * MONACO_RENDERED_TEXT_WIDTH_SCALER), MONACO_HEIGHT_OF_A_LINE_OF_TEXT * getTextHeight()};
    }

    TextComponent() {
        this->text = "Robert C. Martin";
        surfaceSize = {static_cast<RenderedVal>(getTextWidth() * MONACO_RENDERED_TEXT_WIDTH_SCALER), MONACO_HEIGHT_OF_A_LINE_OF_TEXT};
    }


protected:
    [[nodiscard]] int getTextHeight() const {
        int height = 0;
        std::istringstream textStream(text);
        std::string token;
        while(std::getline(textStream, token, '\n')) {
            height++;
        }
        return height;
    }

    [[nodiscard]] unsigned int getTextWidth() const {
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


#endif
