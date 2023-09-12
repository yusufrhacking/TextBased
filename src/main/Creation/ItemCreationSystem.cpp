#include "ItemCreationSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CreateItemEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

ItemCreationSystem::ItemCreationSystem(){
    listenToEvents();
}
void ItemCreationSystem::listenToEvents(){
    eventBus->listenToEvent<CreateItemEvent>(this, &ItemCreationSystem::onCreate);
}
void ItemCreationSystem::onCreate(CreateItemEvent& event){
    switch (event.item){
        case Item::AXE: createAxe();
        default: break;
    }
}