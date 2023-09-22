#ifndef TEXTBASED_TERMINALRENDERSYSTEM_H
#define TEXTBASED_TERMINALRENDERSYSTEM_H


#include "../ECSObjects/System.h"
#include "../Rendering/EntityRenderSystem.h"

class TerminalRenderSystem: public RenderSystem {
private:
    std::string currentText;
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
};


#endif //TEXTBASED_TERMINALRENDERSYSTEM_H
