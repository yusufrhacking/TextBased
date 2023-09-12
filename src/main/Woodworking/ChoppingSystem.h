#ifndef TEXTBASED_CHOPPINGSYSTEM_H
#define TEXTBASED_CHOPPINGSYSTEM_H
#include "../ECSObjects/System.h"
#include "ChopEvent.h"

class ChoppingSystem: public System {
public:
    ChoppingSystem();
private:
    void listenToEvents();
    void onChop(ChopEvent& event);

    Position getAxePosition(Entity mainPlayer);

    bool isInChoppingRange(Position axePosition, Position treePosition, float allowedDistance);

    std::string chopTreeText(std::string treeText);
};


#endif //TEXTBASED_CHOPPINGSYSTEM_H
