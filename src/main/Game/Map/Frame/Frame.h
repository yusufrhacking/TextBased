#ifndef TEXTBASED_FRAME_H
#define TEXTBASED_FRAME_H
#include "OpenAt.h"

enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};

class Frame {
public:
    OpenAt openAt;
    virtual ~Frame() = default;
};


#endif //TEXTBASED_FRAME_H
