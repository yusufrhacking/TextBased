#ifndef TEXTBASED_FIRSTSYSTEM_H
#define TEXTBASED_FIRSTSYSTEM_H

#include "../../Design/Objects/System.h"

class FirstSystem: public System{
public:
    virtual void run() = 0;
};

#endif //TEXTBASED_FIRSTSYSTEM_H
