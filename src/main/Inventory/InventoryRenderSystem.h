#ifndef TEXTBASED_INVENTORYRENDERSYSTEM_H
#define TEXTBASED_INVENTORYRENDERSYSTEM_H
#include "../Rendering/FixedRenderSystem.h"
#include "Inventory.h"

class InventoryRenderSystem: public FixedRenderSystem {
private:
    Position inventoryStartingPosition{0,0};
    float X_OFFSET = 20;
    float Y_OFFSET = 20;
public:
    InventoryRenderSystem() = default;
    void render(const std::shared_ptr<Renderer>& renderer) override;
    void render(const std::shared_ptr<Renderer>& renderer, const Inventory& inventory);
};


#endif //TEXTBASED_INVENTORYRENDERSYSTEM_H
