#ifndef PLATFORMGENERATIONSYSTEM_H
#define PLATFORMGENERATIONSYSTEM_H
#include "../ECSObjects/System.h"


class PlatformGenerationSystem: public System {

public:
    PlatformGenerationSystem(Position startPosition, std::vector<std::string> stepStrs);

};



#endif //PLATFORMGENERATIONSYSTEM_H
