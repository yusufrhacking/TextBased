#ifndef TEXTBASED_TERMINALRENDERSYSTEM_H
#define TEXTBASED_TERMINALRENDERSYSTEM_H


#include "../ECSObjects/System.h"
#include "../Rendering/EntityRenderSystem.h"

class TerminalRenderSystem: public EntityRenderSystem {
public:
    TerminalRenderSystem();
    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;
};


#endif //TEXTBASED_TERMINALRENDERSYSTEM_H
