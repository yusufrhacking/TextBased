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

    bool isInChoppingRange(Position axePosition, Position treePosition, const TextComponent& treeTextComponent, float allowedDistance);

    std::string chopTreeText(const std::string& treeText);

    bool isWithinTreeBounds(Position axePosition, Position treePosition, const TextComponent &treeTextComponent);

    Position
    getClosestPartOfTree(Position axePosition, Position treePosition, const TextComponent &treeTextComponent);

    bool isWithinAllowedDistance(Position axePosition, Position point, float allowedDistance);
};


#endif //TEXTBASED_CHOPPINGSYSTEM_H
