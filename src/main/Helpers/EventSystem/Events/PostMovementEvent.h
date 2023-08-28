#ifndef TEXTBASED_POSTMOVEMENTEVENT_H
#define TEXTBASED_POSTMOVEMENTEVENT_H

#include "ReadyToMoveEvent.h"
struct PostMovementEvent: public ReadyToMoveEvent{
    using ReadyToMoveEvent::ReadyToMoveEvent;
};

#endif //TEXTBASED_POSTMOVEMENTEVENT_H
