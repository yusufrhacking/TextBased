#ifndef TEXTBASED_WORDDEPOSITEVENT_H
#define TEXTBASED_WORDDEPOSITEVENT_H

#include "../EventSystem/Event.h"
#include "Letter.h"
#include <string>

struct WordDepositEvent: public Event{
    std::vector<Letter> letters;
    explicit WordDepositEvent(const std::string& word){
        for(auto character: word){
            letters.push_back(char_to_enum(character));
        }
    }
};

#endif //TEXTBASED_WORDDEPOSITEVENT_H
