#ifndef TEXTBASED_FRAMECELL_H
#define TEXTBASED_FRAMECELL_H
#include <memory>
#include "../Frame/Frame.h"
#include "../../../Helpers/Objects/Position.h"
#include <vector>
#include <bitset>

enum Biome{
    BLANK,
    FOREST
};

struct FrameCell {
private:
    std::vector<FrameCell*> neighbors;
public:
    std::unique_ptr<Frame> frame;
    bool isFilled;
    Biome biome;
    Position gameReferencePosition;

    FrameCell();

    FrameCell(const FrameCell& other): neighbors(4) {
        isFilled = other.isFilled;
        biome = Biome::BLANK;
        // Copy any other member variables here
    }

    std::vector<FrameCell*> getNeighbors() const;

    void setNeighborFrame(Direction direction, FrameCell* neighbor);

    bool isOpenAt(Direction direction) const;

    static Direction getOppositeDirection(Direction direction);

    std::bitset<4> getOpenPathsSignature();
};


#endif //TEXTBASED_FRAMECELL_H
