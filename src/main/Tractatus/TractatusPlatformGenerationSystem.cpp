#include "TractatusPlatformGenerationSystem.h"
#include "../EventSystem/EventBus.h"

#include "../Platformer/TextStepPrefab.h"
#include "../MainPlayer/MainPlayerComponent.h"
#include "../Middlemarch/SubjectComponent.h"
#include "../PositionsAndMovement/CollisionEvent.h"
#include "../Platformer/PlatformComponent.h"
#include "PropositionComponent.h"
#include "../Text/Split.h"

extern std::unique_ptr<ECSManager> ecsManager;

extern std::unique_ptr<EventBus> eventBus;

TractatusPlatformGenerationSystem::TractatusPlatformGenerationSystem(Position startPosition, std::vector<std::string> stepStrs):
        startPosition(startPosition), stepStrs(std::move(stepStrs)){
    nextStepPos = startPosition;
    nextStepPos = nextStepPos - stepJump;

    listenToEvents();

    // Create all of the entities ahead of time, add the live component on createNextStep

    Entity terrainBase = ecsManager->createEntity();

    ecsManager->addComponentToEntity<LiveComponent>(terrainBase);
    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, startPosition);
    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "1.0 The world is all that is the case");
    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::ONE);


    terrainBase = ecsManager->createEntity();
    entities.push(terrainBase);
    startPosition += Position(450, -100);

    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, startPosition);
    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "1.1 The world is the totality of facts, not of things");
    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::ONE);

    terrainBase = ecsManager->createEntity();
    entities.push(terrainBase);
    startPosition += Position(-600, -100);

    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, startPosition);
    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "1.11 The world is determined by the facts, \nand by their being all all the facts.");
    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::ONE);

    terrainBase = ecsManager->createEntity();
    entities.push(terrainBase);
    startPosition += Position(450, -100);

    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, startPosition);
    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "1.12 For the totality of facts determines what is the case,\n and also whatever is is not not the the case.");
    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::ONE);

    terrainBase = ecsManager->createEntity();
    entities.push(terrainBase);
    startPosition += Position(450, -100);

    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, startPosition);
    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "1.13 The facts in logical space are the world.");
    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::ONE);

    terrainBase = ecsManager->createEntity();
    entities.push(terrainBase);
    startPosition += Position(-450, -100);

    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, startPosition);
    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "1.2 The world divides into facts.");
    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::ONE);

    terrainBase = ecsManager->createEntity();
    entities.push(terrainBase);
    startPosition += Position(-450, -100);

    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, startPosition);
    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "1.21 Each item item can be the case or not the case \nwhile everything else else remains the the same.");
    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::ONE);

    terrainBase = ecsManager->createEntity();
    entities.push(terrainBase);
    startPosition += Position(-450, -100);

    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, startPosition);
    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "2.0 What is the case — a fact — is the existence of states of affairs.");
    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::TWO);

    terrainBase = ecsManager->createEntity();
    entities.push(terrainBase);
    startPosition += Position(-450, -100);

    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, startPosition);
    ecsManager->addComponentToEntity<TextComponent>(terrainBase, "2.01 A state of affairs (a state of things) is a combination of objects (things).");
    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
    ecsManager->addComponentToEntity<PropositionComponent>(terrainBase, TractatusLayer::TWO);
}

void TractatusPlatformGenerationSystem::listenToEvents() {
    eventBus->listenToEvent<CollisionEvent>(this, &TractatusPlatformGenerationSystem::screenCollisionForLanding);
}

void TractatusPlatformGenerationSystem::screenCollisionForLanding(CollisionEvent& event){
    if (ecsManager->hasComponent<PlatformComponent>(event.a)) {
        if (ecsManager->hasComponent<SubjectComponent>(event.b)) {
            if(ecsManager->getComponentFromEntity<PlatformComponent>(event.a).beenReached) {
                return;
            }
            ecsManager->getComponentFromEntity<PlatformComponent>(event.a).beenReached = true;
            toNextStep();
        }
    }
    if (ecsManager->hasComponent<PlatformComponent>(event.b)) {
        if (ecsManager->hasComponent<SubjectComponent>(event.a)) {
            if(ecsManager->getComponentFromEntity<PlatformComponent>(event.b).beenReached) {
                return;
            }
            ecsManager->getComponentFromEntity<PlatformComponent>(event.b).beenReached = true;
            toNextStep();
        }
    }
}

void TractatusPlatformGenerationSystem::toNextStep() {
    if (!entities.empty()){
        ecsManager->addComponentToEntity<LiveComponent>(entities.front());
        const auto& propositionComponent = ecsManager->getComponentFromEntity<PropositionComponent>(entities.front());
        if (propositionComponent.layer == TractatusLayer::TWO){
            // ecsManager->addSystem<FactSystem>();
        }
        entities.pop();
    }
}
