#include "InventoryRenderSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "InventoryComponent.h"


extern std::unique_ptr<ECSManager> ecsManager;

void InventoryRenderSystem::render(const std::shared_ptr<Renderer> &renderer) {
    auto mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
    auto mainPlayerInventory = ecsManager->getComponentFromEntity<InventoryComponent>(mainPlayer).inventory;

}
