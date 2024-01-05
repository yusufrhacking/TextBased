#ifndef TEXTBASED_UNPROCESSEDKEYBOARDMOVEMENTSYSTEM_H
#define TEXTBASED_UNPROCESSEDKEYBOARDMOVEMENTSYSTEM_H
#include <vector>
#include "UnprocessedMovement.h"
#include "../HighLevel/ECSManager.h"
#include "../ECSObjects/FirstSystem.h"
#include <tuple>

#include "../ECSObjects/FinalSystem.h"


class UnprocessedMovementSystem: public FinalSystem {
    std::unique_ptr<std::vector<UnprocessedMovement>> unprocessedMovements;
    std::unordered_map<int, Velocity> totalChangeForEntities;

public:
    UnprocessedMovementSystem();

    void queueMovement(UnprocessedMovement movement);

    void update(double deltaTime) override;

};


#endif
