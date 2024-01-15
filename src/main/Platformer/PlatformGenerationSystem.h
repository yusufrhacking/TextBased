#ifndef PLATFORMGENERATIONSYSTEM_H
#define PLATFORMGENERATIONSYSTEM_H
#include "../ECSObjects/System.h"


class PlatformGenerationSystem: public System {
    Position stepJump{100, -50};
    float prevWordX = 0;
    float direction = 1;
public:
    PlatformGenerationSystem(Position startPosition, std::vector<std::string> stepStrs);

};



#endif //PLATFORMGENERATIONSYSTEM_H
