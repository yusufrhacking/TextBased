#ifndef TEXTBASED_CHARACTERDEPOSITEVENT_H
#define TEXTBASED_CHARACTERDEPOSITEVENT_H
#include "Letter.h"

#include "../EventSystem/Event.h"

struct CharacterDepositEvent: public Event{
    explicit CharacterDepositEvent(Letter character): character(character){}

    Letter character;
};

#endif //TEXTBASED_CHARACTERDEPOSITEVENT_H
