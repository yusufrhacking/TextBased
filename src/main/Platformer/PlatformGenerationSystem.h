#ifndef PLATFORMGENERATIONSYSTEM_H
#define PLATFORMGENERATIONSYSTEM_H
#include "../ECSObjects/System.h"


class PlatformGenerationSystem: public System {
    Position startPosition{};
    Position stepJump{100, -50};
    Position nextStepPos{};
    float prevWordX = 0;
    float direction = 1;
    size_t stepInd = 0;
    void createNextStep(const std::string&nextStepStr);
public:

    PlatformGenerationSystem(Position startPosition, std::vector<std::string> stepStrs);

};



#endif //PLATFORMGENERATIONSYSTEM_H
