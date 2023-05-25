#ifndef TEXTBASED_UNPROCESSEDMOVEMENTSYSTEM_H
#define TEXTBASED_UNPROCESSEDMOVEMENTSYSTEM_H
#include <vector>
#include "UnprocessedMovement.h"
#include "../../../Design/Objects/System.h"
#include "../../../Design/Managers/ECSManager.h"
#include <tuple>


class UnprocessedMovementSystem: public System {
    std::unique_ptr<std::vector<UnprocessedMovement>> unprocessedMovements;
    std::unordered_map<int, Velocity> totalChangeForEntities;

public:
    UnprocessedMovementSystem();

    void queueMovement(UnprocessedMovement movement);

    void processMovement();

};


#endif
