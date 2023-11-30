#ifndef HIDEUIEVENT_H
#define HIDEUIEVENT_H

#include <string>

#include "../EventSystem/Event.h"

struct HideUIEvent: Event {
    std::string toHide;
    explicit HideUIEvent(std::string toHide): toHide(std::move(toHide)) {

    }
};

#endif //HIDEUIEVENT_H
