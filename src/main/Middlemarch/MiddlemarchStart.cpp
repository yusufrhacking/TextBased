#include "MiddlemarchStart.h"
#include "../Diegesis/EngineerSpeakEvent.h"
#include "../EventSystem/EventBus.h"
#include "PreludeText.h"
#include "../ECSObjects/Entity.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "NovelTextComponent.h"

extern std::unique_ptr<EventBus> eventBus;
extern std::unique_ptr<ECSManager> ecsManager;

MiddlemarchStart::MiddlemarchStart(Position startingPosition): startPosition(startingPosition) {
    speakEngineer();
}

void MiddlemarchStart::speakEngineer() const {
    eventBus->emitEvent<EngineerSpeakEvent>("Middlemarch");
    eventBus->emitEvent<EngineerSpeakEvent>("by George Eliot");

    Entity preludeTextEntity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(preludeTextEntity, preludeText);
    ecsManager->addComponentToEntity<PositionComponent>(preludeTextEntity, Window::deriveRelativeTopLeft(startPosition));
    ecsManager->addComponentToEntity<LiveComponent>(preludeTextEntity);
    ecsManager->addComponentToEntity<NovelTextComponent>(preludeTextEntity);

    //Create text component for it
    //No collision component
    //I can either manually put in line breaks or I can set up the more complex stylizer with this
    //the stylizer will check for like NovelText component and will know to wrap it
}
