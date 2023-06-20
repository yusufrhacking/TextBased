#ifndef TEXTBASED_FRAMECELL_H
#define TEXTBASED_FRAMECELL_H
#include <memory>
#include "../Frame/Frame.h"
#include "../../../Helpers/Objects/Position.h"
#include "../../../Helpers/Objects/MapPosition.h"
#include <vector>
#include <bitset>

enum Biome{
    BLANK,
    FOREST
};

struct FrameCell {
    std::unique_ptr<Frame> frame;
    bool isFilled;
    Biome biome;
    Position gameReferencePosition;
    MapPosition mapPosition;

    FrameCell();

    FrameCell(const FrameCell& other){
        isFilled = other.isFilled;
        biome = Biome::BLANK;
        // Copy any other member variables here
    }

    bool isOpenAt(Direction direction) const;

    static Direction getOppositeDirection(Direction direction);

    std::bitset<4> getOpenPathsSignature();
};


#endif //TEXTBASED_FRAMECELL_H
