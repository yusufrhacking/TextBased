#ifndef TEXTBASED_LIVETERMINALRENDERSYSTEM_H
#define TEXTBASED_LIVETERMINALRENDERSYSTEM_H

#include "TerminalTextUpdateEvent.h"
#include "../ECSObjects/System.h"
#include "../Rendering/EntityRenderSystem.h"
#include "TakingInputFlipEvent.h"
#include "../TextCommands/AuthoredCommand.h"
#include "TerminalRenderer.h"


class LiveTerminalRenderSystem: public RenderSystem {
private:
    std::string currentText;
    Position startingTerminalPosition;
    TerminalRenderer terminalRenderer{};
    bool isTerminalLive;

public:
    LiveTerminalRenderSystem(Position startingTerminalPosition);
    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;

    void renderLiveLine(const std::shared_ptr<Renderer> &renderer);

    void onTerminalRender(TerminalTextUpdateEvent& event);

    void onTakingInputFlip(TakingInputFlipEvent& event);

};


#endif //TEXTBASED_LIVETERMINALRENDERSYSTEM_H
