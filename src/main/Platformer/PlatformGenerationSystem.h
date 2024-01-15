#ifndef PLATFORMGENERATIONSYSTEM_H
#define PLATFORMGENERATIONSYSTEM_H
#include "../ECSObjects/System.h"


class PlatformGenerationSystem: public System {
    Position startPosition{};
    Position stepJump{100, -50};
    float prevWordX = 0;
    float direction = 1;
    void createNextStep(Position&nextStepPos, const std::string&nextStepStr);
public:

    PlatformGenerationSystem(Position startPosition, std::vector<std::string> stepStrs);

};



#endif //PLATFORMGENERATIONSYSTEM_H
