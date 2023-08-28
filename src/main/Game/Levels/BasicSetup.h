#ifndef TEXTBASED_BASICSETUP_H
#define TEXTBASED_BASICSETUP_H
#include "../../ECS/Systems/UpdateSystems/AutonomousMovementSystem.h"
#include "../TextGenerator.h"
#include "../../ECS/Components/CollisionComponent.h"
#include "../../Helpers/Objects/Position.h"
#include "../../ECS/Design/Managers/ECSManager.h"
#include <memory>
#include "../../ECS/Systems/UpdateSystems/CollisionCheckSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

class BasicSetup {
public:
    void setup();

private:
    void createPlayer();
    Entity witt;

    void createTree();
};


#endif //TEXTBASED_BASICSETUP_H
