#ifndef TEXTBASED_UNPROCESSEDKEYBOARDMOVEMENTSYSTEM_H
#define TEXTBASED_UNPROCESSEDKEYBOARDMOVEMENTSYSTEM_H
#include <vector>
#include "UnprocessedMovement.h"
#include "../../../Design/Objects/System.h"
#include "../HighLevel/ECSManager.h"
#include "../ECSObjects/FirstSystem.h"
#include <tuple>


class UnprocessedKeyboardMovementSystem: public FirstSystem {
    std::unique_ptr<std::vector<UnprocessedMovement>> unprocessedMovements;
    std::unordered_map<int, Velocity> totalChangeForEntities;

public:
    UnprocessedKeyboardMovementSystem();

    void queueMovement(UnprocessedMovement movement);

    void run() override;

};


#endif
