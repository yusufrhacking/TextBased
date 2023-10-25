#ifndef TEXTBASED_AXECOMPONENT_H
#define TEXTBASED_AXECOMPONENT_H

#include "../PositionsAndMovement/Position.h"

struct AxeComponent{
    static Position AXE_POSITION_OFFSET;
    int axeDamageToTree = 3;
    AxeComponent() = default;
};

#endif //TEXTBASED_AXECOMPONENT_H
