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


Position GameObject::getRenderPosition(Position anchorPosition) {
    WindowNum heightOffset = getHeightOffset();

    Position renderPosition;
    double xPos = anchorPosition.xPos;
    double yPos = anchorPosition.yPos - heightOffset;

    renderPosition = {xPos, yPos};

    return renderPosition;
}

WindowNum GameObject::getHeightOffset() {
    return getTextHeight() * (RENDERED_TEXT_HEIGHT+RENDERED_LINE_HEIGHT);
}

