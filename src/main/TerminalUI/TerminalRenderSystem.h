#ifndef TEXTBASED_TERMINALRENDERSYSTEM_H
#define TEXTBASED_TERMINALRENDERSYSTEM_H

#include "TerminalTextUpdateEvent.h"
#include "../ECSObjects/System.h"
#include "../Rendering/EntityRenderSystem.h"
#include "TakingInputFlipEvent.h"


class TerminalRenderSystem: public RenderSystem {
private:
    std::string currentText;
    bool isTerminalLive = false;
public:
    static float TERMINAL_X_START;
    static float BOTTOM_WINDOW_OFFSET;
    float TERMINAL_Y_START = (float)Window::windowHeight - (BOTTOM_WINDOW_OFFSET-TERMINAL_MONACO_HEIGHT_LINE_OF_TEXT);;
    int showUnderscore = 0;
    static float TERMINAL_INIT_X_OFFSET;
    static float UNDERSCORE_Y_OFFSET;
    static float TEXT_OFFSET;

    TerminalRenderSystem();
    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;

    void onTerminalRender(TerminalTextUpdateEvent& event);

    void onTakingInputFlip(TakingInputFlipEvent& event);

    void renderUnderscore(Entity entity, const std::shared_ptr<Renderer> &sharedPtr);
};


#endif //TEXTBASED_TERMINALRENDERSYSTEM_H