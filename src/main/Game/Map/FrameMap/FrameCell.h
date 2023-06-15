#ifndef TEXTBASED_FRAMECELL_H
#define TEXTBASED_FRAMECELL_H
#include <memory>
#include "../Frame/Frame.h"

enum Biome{
    FOREST
};

struct FrameCell {
    std::unique_ptr<Frame> frame;
    bool isFilled;
    Biome biome;

    FrameCell(){
        isFilled = false;
    }

    FrameCell(const FrameCell& other) {
        isFilled = other.isFilled;
        // Copy any other member variables here
    }
};



#endif //TEXTBASED_FRAMECELL_H
