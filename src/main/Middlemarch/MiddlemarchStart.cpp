#include "MiddlemarchStart.h"

#include <thread>

#include "../Diegesis/EngineerSpeakEvent.h"
#include "../EventSystem/EventBus.h"
#include "PreludeText.h"
#include "../ECSObjects/Entity.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "NovelTextComponent.h"
#include "SubjectComponent.h"
#include "../Spawning/SupremePowerComponent.h"
#include "../Spawning/SpawnAbyzComponent.h"
#include "../Gravity/GravityComponent.h"
#include "../Gravity/JumpingComponent.h"
#include "../PositionsAndMovement//VelocityComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../Health/HealthComponent.h"
#include "../MainPlayer/RotateComponent.h"
#include "../Inventory/InventoryComponent.h"
#include "../MainPlayer/MainPlayerComponent.h"
#include "../Platformer/PlatformGenerationSystem.h"
#include "../Platformer/TargetComponent.h"
#include "../Platformer/TextStepPrefab.h"
#include "../PositionsAndMovement/RightLeftMovementComponent.h"

extern std::unique_ptr<EventBus> eventBus;
extern std::unique_ptr<ECSManager> ecsManager;


MiddlemarchStart::MiddlemarchStart(Position startingPosition): startPosition(startingPosition) {
    speakEngineer();

    Position subjectPosition{11895, 10532};

    createSubject(subjectPosition);

    Position avilaPosition = subjectPosition + Position(0, 800);
    std::vector<std::string> nextSteps = {
        "from rugged Avila",
        "That child-pilgrimage",
        "romances of chivalry",
        "social conquests of\n  a brilliant girl",
        "spiritual grandeur",
        "social faith",
        "yearning of womanhood",
        "blundering lives",
        "inconvenient indefiniteness"
    };
    ecsManager->addSystem<PlatformGenerationSystem>(avilaPosition, nextSteps);
    
    createTarget();

    Position supremePowerPosition = Window::deriveRelativeTopLeft(subjectPosition);
    supremePowerPosition.x += Window::getMiddlePosition().x;
    supremePowerPosition.x -= TextComponent::getSurfaceSize("Supreme Power").width/2;

    Entity supremePower = ecsManager->createEntity();
    ecsManager->addComponentToEntity<LiveComponent>(supremePower);
    ecsManager->addComponentToEntity<PositionComponent>(supremePower, supremePowerPosition);
    ecsManager->addComponentToEntity<TextComponent>(supremePower, "Supreme Power");
    ecsManager->addComponentToEntity<RandomRightLeftMovementComponent>(supremePower, 100.0);
    ecsManager->addComponentToEntity<SupremePowerComponent>(supremePower);
    ecsManager->addComponentToEntity<SpawnAbyzComponent>(supremePower);
}

void MiddlemarchStart::createPreludeText() const {
    Entity preludeTextEntity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(preludeTextEntity, shortTesting);
    ecsManager->addComponentToEntity<PositionComponent>(preludeTextEntity, Window::deriveRelativeTopLeft(startPosition));
    ecsManager->addComponentToEntity<LiveComponent>(preludeTextEntity);
    ecsManager->addComponentToEntity<NovelTextComponent>(preludeTextEntity, "Saint Theresa");
}

void MiddlemarchStart::speakEngineer() const {
    eventBus->emitEvent<EngineerSpeakEvent>("Middlemarch by George Eliot");
}


void MiddlemarchStart::createSubject(Position subjectPosition) {
    Entity subject = ecsManager->createEntity();
    ecsManager->addComponentToEntity<LiveComponent>(subject);
    ecsManager->addComponentToEntity<PositionComponent>(subject, subjectPosition);
    ecsManager->addComponentToEntity<TextComponent>(subject, "Saint Theresa");
    ecsManager->addComponentToEntity<MainPlayerComponent>(subject);
    ecsManager->addComponentToEntity<SubjectComponent>(subject);
    ecsManager->addComponentToEntity<GravityComponent>(subject);
    ecsManager->addComponentToEntity<VelocityComponent>(subject);
    ecsManager->addComponentToEntity<CollisionComponent>(subject);
    ecsManager->addComponentToEntity<JumpingComponent>(subject, 200);
    ecsManager->addComponentToEntity<RightLeftMovementComponent>(subject, 100.0);
}

void MiddlemarchStart::createTarget() {
    std::string targetStr = "country of the Moors";
    auto targetSize = TextComponent::getSurfaceSize(targetStr);
    Position targetPosAdjustment(-1.0f * static_cast<float>(targetSize.width), targetSize.height);
    Position targetPosition = Window::deriveRelativeTopRight(startPosition) + targetPosAdjustment;
    TextStepPrefab targetPrefab{targetStr, targetPosition};
    ecsManager->addComponentToEntity<TargetComponent>(targetPrefab.entity);
}
