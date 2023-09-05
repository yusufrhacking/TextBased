#include <spdlog/spdlog.h>
#include "WordComprehensionSystem.h"
#include "../../Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

WordComprehensionSystem::WordComprehensionSystem() {
    listenToEvents();
    listening_to_letters = false;
}

void WordComprehensionSystem::listenToEvents(){
    eventBus->listenToEvent<GameKeyEvent>(this, &WordComprehensionSystem::onText);
}
void WordComprehensionSystem::onText(GameKeyEvent& event){
    if (event.getKey() == GameKey::TEXT_FLIP){
        listening_to_letters = !listening_to_letters;
        spdlog::debug("TEXT FLIPPING to {}", listening_to_letters);
    }
}

