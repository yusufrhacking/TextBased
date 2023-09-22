#ifndef TEXTBASED_FIXEDPOSITIONCOMPONENT_H
#define TEXTBASED_FIXEDPOSITIONCOMPONENT_H

#include "../PositionsAndMovement/Position.h"

struct FixedPositionComponent{
    Position position;
    FixedPositionComponent() = default;
    explicit FixedPositionComponent(Position position): position(position) {}
};

#endif
