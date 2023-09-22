#ifndef TEXTBASED_TERMINALRENDERSYSTEM_H
#define TEXTBASED_TERMINALRENDERSYSTEM_H


#include "../ECSObjects/System.h"
#include "../Rendering/EntityRenderSystem.h"

class TerminalRenderSystem: public RenderSystem {
public:
    static float TERMINAL_X_START;
    static float BOTTOM_WINDOW_OFFSET;
    static float TERMINAL_Y_START;
    int showUnderscore = 0;
    static float TERMINAL_INIT_X_OFFSET;
    static float UNDERSCORE_Y_OFFSET;
    static float TEXT_OFFSET;

    TerminalRenderSystem();
    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;
};


#endif //TEXTBASED_TERMINALRENDERSYSTEM_H
