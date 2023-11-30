#ifndef SHOWUIEVENT_H
#define SHOWUIEVENT_H
#include <string>

#include "../EventSystem/Event.h"

struct ShowUIEvent: Event {
    std::string toShow;
    explicit ShowUIEvent(std::string toShow): toShow(std::move(toShow)){}
};

#endif //SHOWUIEVENT_H
