#ifndef TEXTBASED_ATTACKTYPE_H
#define TEXTBASED_ATTACKTYPE_H

#include "../Creation/Item.h"

enum class AttackType{
    BASIC,
    AXE,
    ABYZ
};


namespace Attacking{
    static int getDamageFromAttackType(AttackType type){
        switch(type){
            case AttackType::BASIC: return 1;
            case AttackType::ABYZ: return 1;
            default: return 1;
        }
    }

    static AttackType getAttackTypeFromItem(Item item){
        switch(item){
            case Item::AXE: return AttackType::AXE;
            default: return AttackType::BASIC;
        }
    }
}

#endif //TEXTBASED_ATTACKTYPE_H
