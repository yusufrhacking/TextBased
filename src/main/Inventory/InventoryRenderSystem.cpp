#include "InventoryRenderSystem.h"
#include "InventoryComponent.h"
#include <string>


void InventoryRenderSystem::render(const std::shared_ptr<Renderer> &renderer, const Inventory &inventory) {
    auto baseSubmittedPosition = inventoryStartingPosition + Position(X_OFFSET, (float)0);

    float count = 1;

    for (auto &itemEntitySetPair: inventory.getInventory()) {
        Item item = itemEntitySetPair.first;
        auto itemCount = itemEntitySetPair.second.size();

        auto name = ItemToString(item);
        auto submittedPosition = baseSubmittedPosition + Position((float) 0, Y_OFFSET * count);

        renderer->renderFixedText(submittedPosition, TextComponent(name + " x" + std::to_string(itemCount)),
                                  StyleComponent(Type::PLAIN_TEXT));

        count++;
    }

}

void InventoryRenderSystem::render(const std::shared_ptr<Renderer> &renderer) {

}
