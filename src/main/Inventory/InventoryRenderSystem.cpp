#include "InventoryRenderSystem.h"
#include "InventoryComponent.h"


void InventoryRenderSystem::render(const std::shared_ptr<Renderer> &renderer, const Inventory &inventory) {
    auto submittedPosition = inventoryStartingPosition + Position(X_OFFSET, Y_OFFSET);
    renderer->renderFixedText(submittedPosition, TextComponent("Axe"),
                              StyleComponent(Type::PLAIN_TEXT));
}

void InventoryRenderSystem::render(const std::shared_ptr<Renderer> &renderer) {

}
