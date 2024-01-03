#ifndef TEXTBASED_UNPROCESSEDKEYBOARDMOVEMENTSYSTEM_H
#define TEXTBASED_UNPROCESSEDKEYBOARDMOVEMENTSYSTEM_H
#include <vector>
#include "UnprocessedMovement.h"
#include "../HighLevel/ECSManager.h"
#include "../ECSObjects/FirstSystem.h"
#include <tuple>


class UnprocessedMovementSystem: public FirstSystem {
    std::unique_ptr<std::vector<UnprocessedMovement>> unprocessedMovements;
    std::unordered_map<int, Velocity> totalChangeForEntities;

public:
    UnprocessedMovementSystem();

    void queueMovement(UnprocessedMovement movement);

    void run() override;

};


#endif
