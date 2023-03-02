#ifndef TEXTBASED_RENDERSYSTEM_H
#define TEXTBASED_RENDERSYSTEM_H


#include "../Design/Objects/System.h"
#include "../Components/PositionComponent.h"
#include "../Components/SpriteComponent.h"
#include "../Design/Managers/ECSManager.h"

class RenderSystem: public System {
public:
    explicit RenderSystem();

    void update(std::shared_ptr<Renderer> renderer);

private:
};


#endif //TEXTBASED_RENDERSYSTEM_H
