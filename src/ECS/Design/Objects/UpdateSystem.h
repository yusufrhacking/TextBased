#ifndef TEXTBASED_UPDATESYSTEM_H
#define TEXTBASED_UPDATESYSTEM_H

#include "System.h"

class UpdateSystem: public System {
public:
    virtual void update(double deltaTime) = 0;
};


#endif //TEXTBASED_UPDATESYSTEM_H
