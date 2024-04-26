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
#include "PropositionComponent.h"
#include "../Platformer/PlatformGenerationSystem.h"
#include "TractatusPlatformGenerationSystem.h"


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

    Position terrainBasePosition = startingPosition + Position(0, 800) - Position(TextComponent::getSurfaceSize(wittgensteinStr).width, 0.0f);

    std::vector<std::string> tractatusPart1 = {
            "1.0 The world is all that is the case",
            "1.1 The world is the totality of facts, not of things",
            "1.11 The world is determined by the facts, \nand by their being all all the facts.",
            "1.12 For the totality of facts determines what is the case,\n and also whatever is is not not the the case.",
            "1.13 The facts in logical space are the world.",
            "1.2 The world divides into facts.",
            "1.21 Each item item can be the case or not the case \nwhile everything else else remains the the same.",
    };

    ecsManager->addSystem<TractatusPlatformGenerationSystem>(terrainBasePosition, tractatusPart1);
//
//
//    Entity terrainBase = ecsManager->createEntity();
//
//    ecsManager->addComponentToEntity<LiveComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, terrainBasePosition);
//    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "1.0 The world is all that is the case");
//    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::ONE);
//
//
//    terrainBase = ecsManager->createEntity();
//   terrainBasePosition += Position(450, -100);
//
//    ecsManager->addComponentToEntity<LiveComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, terrainBasePosition);
//    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "1.1 The world is the totality of facts, not of things");
//    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::ONE);
//
//    terrainBase = ecsManager->createEntity();
//    terrainBasePosition += Position(-600, -100);
//
//    ecsManager->addComponentToEntity<LiveComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, terrainBasePosition);
//    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "1.11 The world is determined by the facts, \nand by their being all all the facts.");
//    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::ONE);
//
//    terrainBase = ecsManager->createEntity();
//    terrainBasePosition += Position(450, -100);
//
//    ecsManager->addComponentToEntity<LiveComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, terrainBasePosition);
//    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "1.12 For the totality of facts determines what is the case,\n and also whatever is is not not the the case.");
//    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::ONE);
//
//    terrainBase = ecsManager->createEntity();
//    terrainBasePosition += Position(450, -100);
//
//    ecsManager->addComponentToEntity<LiveComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, terrainBasePosition);
//    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "1.13 The facts in logical space are the world.");
//    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::ONE);
//
//    terrainBase = ecsManager->createEntity();
//    terrainBasePosition += Position(-450, -100);
//
//    ecsManager->addComponentToEntity<LiveComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, terrainBasePosition);
//    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "1.2 The world divides into facts.");
//    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::ONE);
//
//    terrainBase = ecsManager->createEntity();
//    terrainBasePosition += Position(-450, -100);
//
//    ecsManager->addComponentToEntity<LiveComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, terrainBasePosition);
//    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "1.21 Each item item can be the case or not the case \nwhile everything else else remains the the same.");
//    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
//    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::ONE);
}
