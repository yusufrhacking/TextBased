#ifndef TEXTBASED_UNPROCESSEDKEYBOARDMOVEMENTSYSTEM_H
#define TEXTBASED_UNPROCESSEDKEYBOARDMOVEMENTSYSTEM_H
#include <vector>
#include "../MainPlayer/UnprocessedMovement.h"
#include "../HighLevel/ECSManager.h"
#include "../ECSObjects/FirstSystem.h"
#include <tuple>

#include "../ECSObjects/FinalSystem.h"


class MovementSystem: public FinalSystem {
    std::unique_ptr<std::vector<UnprocessedMovement>> unprocessedMovements;
    std::unordered_map<int, Velocity> totalChangeForEntities;

public:
    MovementSystem();

    void queueMovement(UnprocessedMovement movement);

    void runXMotion(double deltaTime);

    void runYMotion(double deltaTime);

    void buildTotalChange();

    void update(double deltaTime) override;

};


#endif
