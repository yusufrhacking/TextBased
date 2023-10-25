#ifndef TEXTBASED_CREATELETTERATPOSITIONEVENT_H
#define TEXTBASED_CREATELETTERATPOSITIONEVENT_H

#include "Item.h"
#include "../ECSObjects/Entity.h"
#include "../EventSystem/Event.h"
#include "../PositionsAndMovement/Position.h"
#include "../Lettering/Letter.h"

struct CreateLetterAtPositionEvent: public Event{
    Letter letter;
    Position position;
    CreateLetterAtPositionEvent(Letter letter, Position position): letter(letter), position(position) {}
};

#endif //TEXTBASED_CREATELETTERATPOSITIONEVENT_H
