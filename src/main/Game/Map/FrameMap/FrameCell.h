#ifndef TEXTBASED_FRAMECELL_H
#define TEXTBASED_FRAMECELL_H
#include <memory>
#include "../Frame/Frame.h"
#include <vector>


enum Biome{
    FOREST = 50
};

struct FrameCell {
    std::unique_ptr<Frame> frame;
    bool isFilled;
    Biome biome;

    FrameCell();

    FrameCell(const FrameCell& other) {
        isFilled = other.isFilled;
        // Copy any other member variables here
    }
};



#endif //TEXTBASED_FRAMECELL_H
