#ifndef TEXTBASED_LEVEL1_H
#define TEXTBASED_LEVEL1_H
#include "../../ECS/Systems/UpdateSystems/AutonomousMovementSystem.h"
#include "../TextGenerator.h"
#include "../../ECS/Components/CollisionComponent.h"
#include "../../Helpers/Objects/Position.h"
#include "../../ECS/Design/Managers/ECSManager.h"
#include <memory>
#include "../../ECS/Systems/EventCreationSystems/CollisionCheckSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

class Level1 {
public:
    void setup();

private:
    void createBobby() const;

    void createJSON() const;

    void createForest(int widthInTrees, Position startingPosition) const;

    void createPlayer();
};


#endif //TEXTBASED_LEVEL1_H
