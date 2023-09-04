#include "WordComprehensionSystem.h"
#include "../../Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

WordComprehensionSystem::WordComprehensionSystem() {
    listenToEvents();
    listening_to_letters = false;
}

void WordComprehensionSystem::listenToEvents(){
    eventBus->listenToEvent<KeyEvent>(this, &WordComprehensionSystem::onText);
}
void WordComprehensionSystem::onText(KeyEvent& event){
    if (listening_to_letters){

    }
}

std::string WordComprehensionSystem::pop_text() {
    return std::string();
}
