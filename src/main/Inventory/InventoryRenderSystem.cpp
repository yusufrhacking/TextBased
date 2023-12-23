#include "InventoryRenderSystem.h"
#include "InventoryComponent.h"
#include <string>


void InventoryRenderSystem::render(const std::shared_ptr<Renderer> &renderer, const Inventory &inventory) {
    renderInventoryShell(renderer, inventory);
    renderInventoryItems(renderer, inventory);
}

void InventoryRenderSystem::render(const std::shared_ptr<Renderer> &renderer) {

}

void InventoryRenderSystem::renderInventoryShell(const std::shared_ptr<Renderer> &renderer, const Inventory &inventory) {
    auto linesUsed = inventory.getUsedSize();
    if (linesUsed == 0){
        return;
    }

    auto topBorderPosition = inventoryStartingPosition;
    auto bottomBorderPosition = inventoryStartingPosition + Position((float)0, Y_OFFSET * (linesUsed + (float)1));

    renderer->renderFixedText(topBorderPosition, TextComponent(std::string(15, '-')), GenericStyleComponent(Type::PLAIN_TEXT));
    renderer->renderFixedText(bottomBorderPosition, TextComponent(std::string(15, '-')), GenericStyleComponent(Type::PLAIN_TEXT));

    for(int i = 1; i <= linesUsed; i++) {
        auto sidePosition = inventoryStartingPosition + Position((float)0, Y_OFFSET * (float)i);
        renderer->renderFixedText(sidePosition, TextComponent("|"), GenericStyleComponent(Type::PLAIN_TEXT));
        renderer->renderFixedText(sidePosition + Position(15*TERMINAL_MONACO_TEXT_WIDTH_SCALER, 0), TextComponent("|"), GenericStyleComponent(Type::PLAIN_TEXT));
    }
}

void InventoryRenderSystem::renderInventoryItems(const std::shared_ptr<Renderer> &renderer, const Inventory &inventory) {
    auto baseSubmittedPosition = inventoryStartingPosition + Position(X_OFFSET, (float)0);

    float count = 1;

    for (auto &itemEntitySetPair: inventory.getInventory()) {
        Item item = itemEntitySetPair.first;
        auto itemCount = itemEntitySetPair.second.size();

        if (itemCount == 0){
            continue;
        }

        auto name = ItemToString(item);
        auto submittedPosition = baseSubmittedPosition + Position((float) 0, Y_OFFSET * count);

        renderer->renderFixedText(submittedPosition, TextComponent(name + " x" + std::to_string(itemCount)),
                                  GenericStyleComponent(Type::PLAIN_TEXT));

        count++;
    }
}

