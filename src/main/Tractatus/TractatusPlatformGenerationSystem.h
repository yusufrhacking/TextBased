#ifndef TEXTBASED_TRACTATUSPLATFORMGENERATIONSYSTEM_H
#define TEXTBASED_TRACTATUSPLATFORMGENERATIONSYSTEM_H
#include "../ECSObjects/System.h"
#include "../PositionsAndMovement/CollisionEvent.h"


class TractatusPlatformGenerationSystem: public System {
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

    TractatusPlatformGenerationSystem(Position startPosition, std::vector<std::string> stepStrs);

};


#endif //TEXTBASED_TRACTATUSPLATFORMGENERATIONSYSTEM_H
