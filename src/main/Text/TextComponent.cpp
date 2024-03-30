#include "TextComponent.h"

TextComponent::TextComponent(std::string text){
    this->text = std::move(text);
}

TextComponent::TextComponent() {
    this->text = "Robert C. Martin";
}

[[nodiscard]] EntitySize TextComponent::getSurfaceSize() const {
    return {static_cast<RenderedVal>(getTextWidth() * MONACO_RENDERED_TEXT_WIDTH_SCALER), MONACO_HEIGHT_OF_A_LINE_OF_TEXT * getTextHeight()};
}

[[nodiscard]] Position TextComponent::getSurfaceSizeAsPosition() const{
    return {(float)(getTextWidth() * MONACO_RENDERED_TEXT_WIDTH_SCALER), (float)(MONACO_HEIGHT_OF_A_LINE_OF_TEXT * getTextHeight())};
}

EntitySize TextComponent::getSurfaceSize(const std::string& text){
    return {static_cast<RenderedVal>(getTextWidthInChars(text) * MONACO_RENDERED_TEXT_WIDTH_SCALER), MONACO_HEIGHT_OF_A_LINE_OF_TEXT *
                                                                                                     getTextHeightInChars(text)};
}

Position TextComponent::getSurfaceSizeAsPosition(const std::string& text){
    return {static_cast<float>(getTextWidthInChars(text) * MONACO_RENDERED_TEXT_WIDTH_SCALER), (float)MONACO_HEIGHT_OF_A_LINE_OF_TEXT *
                                                                                               getTextHeightInChars(text)};
}

Position TextComponent::getSurfaceSizeAsAddablePosition(const std::string& text){
    return {static_cast<float>(getTextWidthInChars(text) * MONACO_RENDERED_TEXT_WIDTH_SCALER), -1*(float)MONACO_HEIGHT_OF_A_LINE_OF_TEXT *
                                                                                               getTextHeightInChars(text)};
}

int TextComponent::getTextHeightInChars(const std::string& text) {
    int height = 0;
    std::istringstream textStream(text);
    std::string token;
    while(std::getline(textStream, token, '\n')) {
        height++;
    }
    return height;
}

unsigned int TextComponent::getTextWidthInChars(const std::string& text) {
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

[[nodiscard]] int TextComponent::getTextHeight() const {
    int height = 0;
    std::istringstream textStream(text);
    std::string token;
    while(std::getline(textStream, token, '\n')) {
        height++;
    }
    return height;
}

[[nodiscard]] unsigned int TextComponent::getTextWidth() const {
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

