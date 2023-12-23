#include "MiddlemarchStart.h"
#include "../Diegesis/EngineerSpeakEvent.h"
#include "../EventSystem/EventBus.h"
#include "PreludeText.h"
#include "../ECSObjects/Entity.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "NovelTextComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../Health/HealthComponent.h"
#include "../MainPlayer/RotateComponent.h"
#include "../Inventory/InventoryComponent.h"

extern std::unique_ptr<EventBus> eventBus;
extern std::unique_ptr<ECSManager> ecsManager;

MiddlemarchStart::MiddlemarchStart(Position startingPosition): startPosition(startingPosition) {
    speakEngineer();

    // Entity witt = ecsManager->createEntity();
    // ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    // ecsManager->addComponentToEntity<PositionComponent>(witt, startingPosition);
    // ecsManager->addComponentToEntity<MainPlayerComponent>(witt, std::make_shared<Velocity>(15, 15));
    // ecsManager->addComponentToEntity<GenericStyleComponent>(witt);
    // ecsManager->addComponentToEntity<CollisionComponent>(witt);
    // ecsManager->addComponentToEntity<InventoryComponent>(witt);
    // ecsManager->addComponentToEntity<LiveComponent>(witt);
    // ecsManager->addComponentToEntity<HealthComponent>(witt, 10);
    // ecsManager->addComponentToEntity<RotationComponent>(witt);
}

void MiddlemarchStart::speakEngineer() const {
    eventBus->emitEvent<EngineerSpeakEvent>("Middlemarch");
    eventBus->emitEvent<EngineerSpeakEvent>("by George Eliot");


    Entity preludeTextEntity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(preludeTextEntity, preludeText);
    ecsManager->addComponentToEntity<PositionComponent>(preludeTextEntity, Position(0,0));
    ecsManager->addComponentToEntity<LiveComponent>(preludeTextEntity);
    ecsManager->addComponentToEntity<NovelTextComponent>(preludeTextEntity);

    //Create text component for it
    //No collision component
    //I can either manually put in line breaks or I can set up the more complex stylizer with this
    //the stylizer will check for like NovelText component and will know to wrap it
}
