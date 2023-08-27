#ifndef TEXTBASED_CANONSYSTEM_H
#define TEXTBASED_CANONSYSTEM_H
#include "../../Design/Objects/System.h"
#include "../../../TheCanon/Canon.h"

class CanonSystem: public System {
    Canon canon;
public:
    CanonSystem(Canon &canon);
};


#endif //TEXTBASED_CANONSYSTEM_H
