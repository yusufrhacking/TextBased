#include "MiddlemarchStart.h"
#include "../Diegesis/EngineerSpeakEvent.h"
#include "../EventSystem/EventBus.h"
#include "PreludeText.h"

extern std::unique_ptr<EventBus> eventBus;

MiddlemarchStart::MiddlemarchStart(Position startingPosition) {
    eventBus->emitEvent<EngineerSpeakEvent>("Middlemarch");
    eventBus->emitEvent<EngineerSpeakEvent>("by George Eliot");
}
