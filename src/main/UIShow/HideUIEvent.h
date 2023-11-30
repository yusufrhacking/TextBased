#ifndef HIDEUIEVENT_H
#define HIDEUIEVENT_H

#include <string>

#include "../EventSystem/Event.h"

class HideUIEvent: public Event {
public:
    std::string toHide;
    explicit HideUIEvent(std::string toHide): toHide(std::move(toHide)){}
};

#endif //HIDEUIEVENT_H
