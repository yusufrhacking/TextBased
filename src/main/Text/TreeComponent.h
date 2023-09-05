#ifndef TEXTBASED_TREECOMPONENT_H
#define TEXTBASED_TREECOMPONENT_H

#include "TextComponent.h"
#include "TextGenerator.h"

struct TreeComponent: public TextComponent{
    TreeComponent(){
        text = TextGenerator::getTreeText();
        surfaceSize = {static_cast<RenderedVal>(getTextWidth() * RENDERED_TEXT_WIDTH_SCALER), HEIGHT_OF_A_LINE_OF_TEXT * getTextHeight()};
    }
};

#endif
