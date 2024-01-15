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
#include "../Gravity/GravityComponent.h"
#include "../Gravity/JumpingComponent.h"
#include "../PositionsAndMovement//VelocityComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../Health/HealthComponent.h"
#include "../MainPlayer/RotateComponent.h"
#include "../Inventory/InventoryComponent.h"
#include "../MainPlayer/MainPlayerComponent.h"
#include "../Platformer/TargetComponent.h"
#include "../Platformer/TextStepPrefab.h"
#include "../PositionsAndMovement/RightLeftMovementComponent.h"

extern std::unique_ptr<EventBus> eventBus;
extern std::unique_ptr<ECSManager> ecsManager;

MiddlemarchStart::MiddlemarchStart(Position startingPosition): startPosition(startingPosition) {
    speakEngineer();

    Position subjectPosition{11895, 10532};

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


    Position avilaPosition = subjectPosition + Position(0, 800);
    Entity avila = ecsManager->createEntity();
    ecsManager->addComponentToEntity<LiveComponent>(avila);
    ecsManager->addComponentToEntity<PositionComponent>(avila,avilaPosition );
    ecsManager->addComponentToEntity<TextComponent>(avila, "rugged Avila");
    ecsManager->addComponentToEntity<GenericStyleComponent>(avila);
    ecsManager->addComponentToEntity<CollisionComponent>(avila);


    std::string nextStepStr = "That child-pilgrimage";
    Position nextStepPos = avilaPosition + Position(200, -50);
    TextStepPrefab nextStepPrefab{nextStepStr, nextStepPos};
    ecsManager->addComponentToEntity<GenericStyleComponent>(nextStepPrefab.entity);

    std::string targetStr = "country of the Moors";
    auto targetSize = TextComponent::getSurfaceSize(targetStr);
    Position targetPosAdjustment(-1.0f * static_cast<float>(targetSize.width), targetSize.height);
    Position targetPosition = Window::deriveRelativeTopRight(startPosition) + targetPosAdjustment;
    TextStepPrefab targetPrefab{targetStr, targetPosition};
    ecsManager->addComponentToEntity<TargetComponent>(targetPrefab.entity);

    // Need other platforms to jump to
    // Need to be able to jump sideways
    // Need abyz on the sides

    // Probably want to make it where the next step appears as you land on the previous one?
    // So I want to do a chain? And a LandEvent that is emitted when the jit lands from the jump system?

    //Supreme Power drops Abyz down from above on top of the platforms
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

void MiddlemarchStart::createWitt(Position startingPosition) {
    Entity witt = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    ecsManager->addComponentToEntity<PositionComponent>(witt, startingPosition);
    ecsManager->addComponentToEntity<KeyboardMovementComponent>(witt, std::make_shared<Velocity>(15, 15));
    ecsManager->addComponentToEntity<GenericStyleComponent>(witt);
    ecsManager->addComponentToEntity<CollisionComponent>(witt);
    ecsManager->addComponentToEntity<InventoryComponent>(witt);
    ecsManager->addComponentToEntity<LiveComponent>(witt);
    ecsManager->addComponentToEntity<HealthComponent>(witt, 10);
    ecsManager->addComponentToEntity<RotationComponent>(witt);
    ecsManager->addComponentToEntity<MainPlayerComponent>(witt);
}
