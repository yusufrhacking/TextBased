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
    if (listening_to_letters){

    }
}

std::string WordComprehensionSystem::pop_text() {
    return std::string();
}
