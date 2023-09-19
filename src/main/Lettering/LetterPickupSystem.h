#ifndef TEXTBASED_LETTERPICKUPSYSTEM_H
#define TEXTBASED_LETTERPICKUPSYSTEM_H


#include "../ECSObjects/UpdateSystem.h"

class LetterPickupSystem: public UpdateSystem {
public:
    LetterPickupSystem();

    void update(double deltaTime) override;

};


#endif //TEXTBASED_LETTERPICKUPSYSTEM_H
