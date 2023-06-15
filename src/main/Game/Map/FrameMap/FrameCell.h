#ifndef TEXTBASED_FRAMECELL_H
#define TEXTBASED_FRAMECELL_H
#include <memory>
#include "../Frame/Frame.h"
#include <vector>

enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};

enum Biome{
    BLANK,
    FOREST
};

struct FrameCell {
    std::unique_ptr<Frame> frame;
    bool isFilled;
    Biome biome;
    std::vector<FrameCell*> neighbors;

    FrameCell();

    FrameCell(const FrameCell& other): neighbors(4) {
        isFilled = other.isFilled;
        biome = Biome::BLANK;
        // Copy any other member variables here
    }

    void setNeighborFrame(Direction direction, FrameCell* neighbor);


    [[nodiscard]] bool isNeighborOpen(Direction direction) const;
};


#endif //TEXTBASED_FRAMECELL_H
