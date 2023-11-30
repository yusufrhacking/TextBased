#ifndef FLIPAXEEVENT_H
#define FLIPAXEEVENT_H
#include "../EventSystem/Event.h"
#include <string>

struct FlipEvent : Event {
    std::string flipped;
    FlipEvent(std::string flipped): flipped(std::move(flipped)){}
};

#endif //FLIPAXEEVENT_H
