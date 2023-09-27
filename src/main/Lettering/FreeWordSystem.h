#ifndef TEXTBASED_FREEWORDSYSTEM_H
#define TEXTBASED_FREEWORDSYSTEM_H


#include "../ECSObjects/System.h"
#include "FreeWordEvent.h"


class FreeWordSystem: public System {
public:
    FreeWordSystem();
    void listenToEvents();
    void onFreeWord(FreeWordEvent& event);
};


#endif //TEXTBASED_FREEWORDSYSTEM_H
