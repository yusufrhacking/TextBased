#ifndef TEXTBASED_LIVETERMINALRENDERSYSTEM_H
#define TEXTBASED_LIVETERMINALRENDERSYSTEM_H

#include "TerminalTextUpdateEvent.h"
#include "../ECSObjects/System.h"
#include "../Rendering/EntityRenderSystem.h"
#include "TakingInputFlipEvent.h"
#include "../TextCommands/AuthoredCommand.h"


class LiveTerminalRenderSystem: public RenderSystem {
private:
    std::string currentText;
    bool isTerminalLive = false;
    Camera unusedCamera{Position{0,0}};
    Position startingTerminalPosition;

public:
    float TERMINAL_Y_START = (float)Window::windowHeight - (BOTTOM_WINDOW_OFFSET-TERMINAL_MONACO_HEIGHT_LINE_OF_TEXT);
    int showUnderscore = 0;

    LiveTerminalRenderSystem(Position startingTerminalPosition);
    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;

    void onTerminalRender(TerminalTextUpdateEvent& event);

    void onTakingInputFlip(TakingInputFlipEvent& event);

    void renderUnderscore(const std::shared_ptr<Renderer> &sharedPtr);

    void renderLiveLine(const std::shared_ptr<Renderer> &renderer);

    void renderPromptSymbol(const std::shared_ptr<Renderer> &renderer);

    void renderLiveText(const std::shared_ptr<Renderer> &renderer);
};


#endif //TEXTBASED_LIVETERMINALRENDERSYSTEM_H
