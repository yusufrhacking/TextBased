#ifndef TEXTBASED_EMMAWOODHOUSESYSTEM_H
#define TEXTBASED_EMMAWOODHOUSESYSTEM_H
#include "../Lettering/CharacterDepositEvent.h"
#include "../ECSObjects/System.h"


class EmmaWoodhouseSystem: public System {
public:
    EmmaWoodhouseSystem();
private:
    void listenToEvents();

    void onDeposit(CharacterDepositEvent &event);

};


#endif //TEXTBASED_EMMAWOODHOUSESYSTEM_H
