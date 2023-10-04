#ifndef TEXTBASED_TREECOMPONENT_H
#define TEXTBASED_TREECOMPONENT_H

#include "../Text/TextComponent.h"
#include "../Text/TextGenerator.h"

struct TreeComponent{
    TreeComponent() = default;

    static Position findTreeMiddle(Position treePosition) {
        auto surface = TextComponent::getSurfaceSize(TextGenerator::getTreeText());
        auto xSize = surface.width/2;
        auto ySize = surface.height/2;
        return treePosition + Position((float)xSize, (float)ySize);
    }
};

#endif
