#include "TractatusStart.h"
#include "../PositionsAndMovement/Position.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../MainPlayer/MainPlayerComponent.h"
#include "../Middlemarch/SubjectComponent.h"
#include "../Gravity/GravityComponent.h"
#include "../PositionsAndMovement/VelocityComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../Gravity/JumpingComponent.h"
#include "../PositionsAndMovement/WalkingComponent.h"
#include "../Platformer/PlatformComponent.h"
#include "../Lettering/LetterPrefab.h"
#include "../Abyz/AbyzComponent.h"
#include "../Abyz/LifeGateComponent.h"
#include "../PositionsAndMovement/RandomRightLeftMovementComponent.h"
#include "../Platformer/HorizontalPlatformMovementComponent.h"
#include "../Diegesis/EngineerSpeakEvent.h"


extern std::unique_ptr<EventBus> eventBus;
extern std::unique_ptr<ECSManager> ecsManager;

TractatusStart::TractatusStart(Position startingPosition): startingPosition() {
    wittgenstein = ecsManager->createEntity();
    std::string wittgensteinStr = "Wittgenstein";
    ecsManager->addComponentToEntity<LiveComponent>(wittgenstein);
    ecsManager->addComponentToEntity<PositionComponent>(wittgenstein, startingPosition);
    ecsManager->addComponentToEntity<TextComponent>(wittgenstein, wittgensteinStr);
    ecsManager->addComponentToEntity<MainPlayerComponent>(wittgenstein);
    ecsManager->addComponentToEntity<SubjectComponent>(wittgenstein);
    ecsManager->addComponentToEntity<GravityComponent>(wittgenstein);
    ecsManager->addComponentToEntity<VelocityComponent>(wittgenstein);
    ecsManager->addComponentToEntity<CollisionComponent>(wittgenstein);
    ecsManager->addComponentToEntity<JumpingComponent>(wittgenstein, 300);
    ecsManager->addComponentToEntity<WalkingComponent>(wittgenstein, 200.0);

    Entity terrainBase = ecsManager->createEntity();
    Position terrainBasePosition = startingPosition + Position(0, 800) - Position(TextComponent::getSurfaceSize(wittgensteinStr).width, 0.0f);

    ecsManager->addComponentToEntity<LiveComponent>(terrainBase);
    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, terrainBasePosition);
    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "1.0 The world is all that is the case");
    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
    ecsManager->addComponentToEntity<GenericStyleComponent>(terrainBase);
}
