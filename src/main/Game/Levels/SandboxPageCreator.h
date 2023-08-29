#ifndef TEXTBASED_SANDBOXPAGECREATOR_H
#define TEXTBASED_SANDBOXPAGECREATOR_H
#include "../../ECS/Systems/UpdateSystems/AutonomousMovementSystem.h"
#include "../TextGenerator.h"
#include "../../ECS/Components/CollisionComponent.h"
#include "../../Helpers/Objects/Position.h"
#include "../../ECS/Design/Managers/ECSManager.h"
#include <memory>
#include "../../ECS/Systems/UpdateSystems/CollisionCheckSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

class SandboxPageCreator {
public:
    SandboxPageCreator(Position startingPosition);

private:
    Position startingPosition;
    void createPlayer();
    Entity witt;

    void createTree();
};


#endif //TEXTBASED_SANDBOXPAGECREATOR_H
