#ifndef TEXTBASED_ATTACKTYPE_H
#define TEXTBASED_ATTACKTYPE_H

enum class AttackType{
    BASIC,
    ABYZ_TO_PLAYER
};


namespace Attacking{
    static int getDamageFromAttackType(AttackType type){
        switch(type){
            case AttackType::BASIC: return 1;
        }
    }
}

#endif //TEXTBASED_ATTACKTYPE_H
