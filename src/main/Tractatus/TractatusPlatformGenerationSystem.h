#ifndef TEXTBASED_TRACTATUSPLATFORMGENERATIONSYSTEM_H
#define TEXTBASED_TRACTATUSPLATFORMGENERATIONSYSTEM_H
#include "../ECSObjects/System.h"
#include "../PositionsAndMovement/CollisionEvent.h"
#include <queue>


class TractatusPlatformGenerationSystem: public System {
    Position startPosition{};
    Position stepJump{100, -50};
    Position nextStepPos{};
    std::vector<std::string> stepStrs;
    float prevWordX = 0;
    float direction = 1;
    int stepsInSameDirection = 0;
    size_t stepInd = 0;
    std::queue<Entity> entities;
public:
    void listenToEvents();

    void screenCollisionForLanding(CollisionEvent& event);

    TractatusPlatformGenerationSystem(Position startPosition, std::vector<std::string> stepStrs);

    void toNextStep();
};


#endif //TEXTBASED_TRACTATUSPLATFORMGENERATIONSYSTEM_H
