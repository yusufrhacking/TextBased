#ifndef SYSTEMADDSYSTEM_H
#define SYSTEMADDSYSTEM_H

#include "../ECSObjects/System.h"
#include "../Middlemarch/EndOfReadingEvent.h"


class SystemAddSystem: public System {
public:
    SystemAddSystem();
private:
    void onEndOfReading(EndOfReadingEvent& event);
};



#endif //SYSTEMADDSYSTEM_H
