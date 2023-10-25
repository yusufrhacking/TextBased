#ifndef TEXTBASED_CHOPPABLECOMPONENT_H
#define TEXTBASED_CHOPPABLECOMPONENT_H

struct ChoppableComponent{
    int intermediateDamage;
    static const int breakAt = 3;
    ChoppableComponent() {
        intermediateDamage = 0;
    }

    [[nodiscard]] bool isReadyToBreak() const{
        return intermediateDamage >= breakAt;
    }

};

#endif //TEXTBASED_CHOPPABLECOMPONENT_H
