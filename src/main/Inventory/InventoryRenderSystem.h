#ifndef TEXTBASED_INVENTORYRENDERSYSTEM_H
#define TEXTBASED_INVENTORYRENDERSYSTEM_H
#include "../Rendering/FixedRenderSystem.h"

class InventoryRenderSystem: public FixedRenderSystem {
public:
    InventoryRenderSystem() = default;
    void render(const std::shared_ptr<Renderer>& renderer) override;
};


#endif //TEXTBASED_INVENTORYRENDERSYSTEM_H
