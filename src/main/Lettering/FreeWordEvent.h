#ifndef TEXTBASED_FREEWORDEVENT_H
#define TEXTBASED_FREEWORDEVENT_H

#include <string>
#include "../Creation/Item.h"
#include "../EventSystem/Event.h"

struct FreeWordEvent: public Event{
    Item type;
    explicit FreeWordEvent(const std::string& word){
        type = StringToItem(word);
    }
};

#endif //TEXTBASED_FREEWORDEVENT_H
