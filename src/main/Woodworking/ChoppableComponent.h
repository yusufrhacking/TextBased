#ifndef TEXTBASED_CHOPPABLECOMPONENT_H
#define TEXTBASED_CHOPPABLECOMPONENT_H

struct ChoppableComponent{
    int intermediateDamage;
    int breakAt;

    ChoppableComponent(){
        intermediateDamage = 0;
        breakAt = 1;
    }

    explicit ChoppableComponent(int breakAt): breakAt(breakAt) {
        intermediateDamage = 0;
    }

    [[nodiscard]] bool isReadyToBreak() const{
        return intermediateDamage >= breakAt;
    }

};

#endif //TEXTBASED_CHOPPABLECOMPONENT_H
