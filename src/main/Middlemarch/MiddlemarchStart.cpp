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
#include "../PositionsAndMovement//VelocityComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../Health/HealthComponent.h"
#include "../MainPlayer/RotateComponent.h"
#include "../Inventory/InventoryComponent.h"
#include "../MainPlayer/MainPlayerComponent.h"

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

    Entity avila = ecsManager->createEntity();
    ecsManager->addComponentToEntity<LiveComponent>(avila);
    ecsManager->addComponentToEntity<PositionComponent>(avila, subjectPosition + Position(25, 800));
    ecsManager->addComponentToEntity<TextComponent>(avila, "Avila");
    ecsManager->addComponentToEntity<GenericStyleComponent>(avila);
    ecsManager->addComponentToEntity<CollisionComponent>(avila);

    // createPreludeText();

    // createWitt(startingPosition);

    //Make Theresa standout in the text
    //Abyz show up at the bottom and chew through it, quickly
    //Theresa turns into entity, has to fight the Abyz
    //Pull out concepts from the prelude to make gamic
    //

    // Gravity hits once all the text is destroyed, and then Avila as text shows up at the bottom
    // Becomes a platformer kinda thing, where you gotta jump up
    // So need gravity system, and to then transform the keyboard movement system into a jumping system


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
