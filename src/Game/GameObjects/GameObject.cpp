#include "GameObject.h"

int GameObject::findTextWidth() {
    int longestSide = 0;
    return longestSide;
}

int GameObject::getTextHeight() {
    int height = 0;
    std::istringstream textStream(text);
    std::string token;
    while(std::getline(textStream, token, '\n')) {
        height++;
    }
    return height;
}

