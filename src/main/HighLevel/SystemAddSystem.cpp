#include "SystemAddSystem.h"

#include "ECSManager.h"
#include "../EventSystem/EventBus.h"
#include "../Middlemarch/EndOfReadingEvent.h"
#include "../Abyz/AbyzPrioritizingSystem.h"

extern std::unique_ptr<EventBus> eventBus;
extern std::unique_ptr<ECSManager> ecsManager;


SystemAddSystem::SystemAddSystem() {
    eventBus->listenToEvent<EndOfReadingEvent>(this, &SystemAddSystem::onEndOfReading);
}

void SystemAddSystem::onEndOfReading(EndOfReadingEvent& event) {
    ecsManager->addSystem<AbyzPrioritizingSystem>();
}
