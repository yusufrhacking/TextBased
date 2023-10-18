#ifndef TEXTBASED_FORESTPREFAB_H
#define TEXTBASED_FORESTPREFAB_H

#include "../PositionsAndMovement/Position.h"
#include "TreeComponent.h"
#include "TreePrefab.h"

struct ForestPrefab{
    ForestPrefab(Position startingPosition, int width, int height){
        auto treeSurface = TextComponent{TextGenerator::getTreeText()}.getSurfaceSize();
        auto treeWidth = (float)treeSurface.width;
        auto treeHeight = (float)treeSurface.height;
        for(int x = 0; x < width; x++){
            for(int y = 0; y < height; y++){
                Position position = startingPosition + Position((float)x * treeWidth, (float)y * treeHeight);
                TreePrefab tree{position};
            }
        }
    }
};

#endif
