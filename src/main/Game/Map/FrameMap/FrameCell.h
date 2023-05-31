#ifndef TEXTBASED_FRAMECELL_H
#define TEXTBASED_FRAMECELL_H
#include <memory>
#include "../Frame/Frame.h"

struct FrameCell {
    std::shared_ptr<Frame> frame;
    bool isFilled;

    FrameCell(){
        isFilled = false;
    }

    FrameCell(const FrameCell& other) {
        isFilled = other.isFilled;
        // Copy any other member variables here
    }

};


#endif //TEXTBASED_FRAMECELL_H
