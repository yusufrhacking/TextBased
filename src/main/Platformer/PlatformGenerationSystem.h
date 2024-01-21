#ifndef PLATFORMGENERATIONSYSTEM_H
#define PLATFORMGENERATIONSYSTEM_H
#include "../ECSObjects/System.h"
#include "../PositionsAndMovement/CollisionEvent.h"


class PlatformGenerationSystem: public System {
    Position startPosition{};
    Position stepJump{100, -50};
    Position nextStepPos{};
    std::vector<std::string> stepStrs;
    float prevWordX = 0;
    float direction = 1;
    size_t stepInd = 0;
    std::vector<Entity> entities;
    void createNextStep(const std::string&nextStepStr);
public:
    void listenToEvents();

    void screenCollisionForLanding(CollisionEvent& event);

    PlatformGenerationSystem(Position startPosition, std::vector<std::string> stepStrs);

};




#endif //PLATFORMGENERATIONSYSTEM_H
