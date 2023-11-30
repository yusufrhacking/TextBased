#ifndef TEXTBASED_HEALTHBARRENDERSYSTEM_H
#define TEXTBASED_HEALTHBARRENDERSYSTEM_H


#include "../Rendering/FixedRenderSystem.h"
#include "HealthComponent.h"
#include "../UIShow/HideHealthBarEvent.h"
#include "../UIShow/ShowHealthBarEvent.h"

class HealthBarRenderSystem: public FixedRenderSystem {
private:
    Position healthBarStartingPosition{600, 0};
    std::string heart = "<3";
    bool toRender = false;
    void onHide(HideHealthBarEvent& event);
    void onShow(ShowHealthBarEvent& event);


public:
    HealthBarRenderSystem();
    void render(const std::shared_ptr<Renderer>& renderer) override;
    void render(const std::shared_ptr<Renderer>& renderer, const HealthComponent& playerHealth);
};



#endif //TEXTBASED_HEALTHBARRENDERSYSTEM_H
