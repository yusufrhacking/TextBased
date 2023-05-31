#ifndef TEXTBASED_FRAMECELL_H
#define TEXTBASED_FRAMECELL_H
#include <memory>
#include "../Frame/Frame.h"

struct FrameCell {
    Frame frame;
    bool isFilled;

    FrameCell(){
        isFilled = false;
    }

};


#endif //TEXTBASED_FRAMECELL_H
