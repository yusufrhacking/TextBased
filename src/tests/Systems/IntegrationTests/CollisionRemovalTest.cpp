#include <catch2/catch_test_macros.hpp>
#include <sys/stat.h>
#include "../../../main/HighLevel/Globals.h"
#include "../../../main/HighLevel/ECSManager.h"
#include "../../../main/Positioning/AutonomousMovementSystem.h"
#include "../../../main/Positioning/CollisionCheckSystem.h"
#include "../../../main/PositionsAndMovement/CollisionHandleSystem.h"

const int X_POINT_OF_COLLISION = 20;
const int Y_POINT_OF_COLLISION = 20;
const int DELTA_TIME = 1;

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;


static void addComponentsToEntities(Entity staticEntity, Entity movingEntity){
    ecsManager->addComponentToEntity<PositionComponent>(
            staticEntity, Position(X_POINT_OF_COLLISION, Y_POINT_OF_COLLISION));
    ecsManager->addComponentToEntity<TextComponent>(staticEntity, "Static Entity");
    Size staticEntitySize = ecsManager->getComponentFromEntity<TextComponent>(staticEntity).surfaceSize;
    ecsManager->addComponentToEntity<CollisionComponent>(staticEntity, staticEntitySize);

    ecsManager->addComponentToEntity<PositionComponent>(movingEntity, Position(0, 0));
    ecsManager->addComponentToEntity<TextComponent>(movingEntity, "Moving Entity");
    Size movingEntitySize = ecsManager->getComponentFromEntity<TextComponent>(movingEntity).surfaceSize;
    ecsManager->addComponentToEntity<CollisionComponent>(movingEntity, movingEntitySize);
    ecsManager->addComponentToEntity<MovementComponent>(
            movingEntity, std::make_shared<Velocity>(X_POINT_OF_COLLISION*DELTA_TIME, Y_POINT_OF_COLLISION*DELTA_TIME));
}
