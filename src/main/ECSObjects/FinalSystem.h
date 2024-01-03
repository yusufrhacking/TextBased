#ifndef FINALSYSTEM_H
#define FINALSYSTEM_H

#include "System.h"

class FinalSystem: public System {
public:
    virtual void update(double deltaTime) = 0;
};

#endif //FINALSYSTEM_H
