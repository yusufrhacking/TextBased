#ifndef TEXTBASED_KEYEVENT_H
#define TEXTBASED_KEYEVENT_H

#include "Event.h"

enum KEY_TYPE{
    W_KEY,
    A_KEY,
    S_KEY,
    D_KEY
};


class KeyEvent: public Event{
public:
    KEY_TYPE keyType;
    explicit KeyEvent(KEY_TYPE keyType){
        this->keyType = keyType;
    }
};

#endif
