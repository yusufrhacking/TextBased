#ifndef TEXTBASED_LETTERCOMPONENT_H
#define TEXTBASED_LETTERCOMPONENT_H

#include "Letter.h"

struct LetterComponent{
    Letter character;
    explicit LetterComponent(Letter character): character(character){}
    LetterComponent() = default;
};

#endif //TEXTBASED_LETTERCOMPONENT_H
