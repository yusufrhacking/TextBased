#ifndef TEXTBASED_FREEWORDEVENT_H
#define TEXTBASED_FREEWORDEVENT_H

#include <string>
#include "../Creation/Item.h"
#include "../EventSystem/Event.h"

struct FreeWordEvent: public Event{
    Item type;
    std::string word;
    explicit FreeWordEvent(std::string word): word(std::move(word)){
        type = StringToItem(this->word);
    }
};

#endif //TEXTBASED_FREEWORDEVENT_H
