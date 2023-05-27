#ifndef TEXTBASED_UNPROCESSEDKEYBOARDMOVEMENTSYSTEM_H
#define TEXTBASED_UNPROCESSEDKEYBOARDMOVEMENTSYSTEM_H
#include <vector>
#include "UnprocessedMovement.h"
#include "../../../Design/Objects/System.h"
#include "../../../Design/Managers/ECSManager.h"
#include <tuple>


class UnprocessedKeyboardMovementSystem: public System {
    std::unique_ptr<std::vector<UnprocessedMovement>> unprocessedMovements;
    std::unordered_map<int, Velocity> totalChangeForEntities;

public:
    UnprocessedKeyboardMovementSystem();

    void queueMovement(UnprocessedMovement movement);

    void processMovement();

};


#endif