#ifndef TEXTBASED_FIRSTLEVEL_H
#define TEXTBASED_FIRSTLEVEL_H
#include "../../ECS/Systems/UpdateSystems/AutonomousMovementSystem.h"
#include "../TextGenerator.h"
#include "../../ECS/Components/CollisionComponent.h"
#include "../../Helpers/Objects/Position.h"
#include "../../ECS/Design/Managers/ECSManager.h"
#include <memory>
#include "../../ECS/Systems/UpdateSystems/CollisionCheckSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

class FirstLevel {
public:
    FirstLevel(Position startingPosition);

private:
    Position startingPosition;
    void createPlayer();
    Entity witt;

    void createTree();

    void createWelcomeText();
};


#endif //TEXTBASED_FIRSTLEVEL_H
