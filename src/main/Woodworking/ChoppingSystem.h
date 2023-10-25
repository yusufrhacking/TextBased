#ifndef TEXTBASED_CHOPPINGSYSTEM_H
#define TEXTBASED_CHOPPINGSYSTEM_H
#include "../ECSObjects/System.h"
#include "ChopEvent.h"
#include "PunchEvent.h"

class ChoppingSystem: public System {
public:
    ChoppingSystem();
private:
    const int PUNCH_TREE_DAMAGE = 1;
    const float CHOPPING_RANGE = 5;
    void listenToEvents();
    void onChop(ChopEvent& event);
    void onPunch(PunchEvent& event);

    void chopWithAxe(Entity axeEntity);

    void chopWithPunch(Entity mainPlayer);

    std::string chopTreeText(const std::string& treeText);

    Position findTreeMiddle(Position treePosition);

    TextComponent getAxeTextComponent(Entity mainPlayer);

    bool hasAxe(Entity mainPlayer);


    Entity getAxeEntity(Entity mainPlayer);

    void tryToChopTree(Entity tree, int damage);
};


#endif //TEXTBASED_CHOPPINGSYSTEM_H
