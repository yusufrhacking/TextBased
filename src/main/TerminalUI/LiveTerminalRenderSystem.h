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
    static float TERMINAL_X_START;
    static float BOTTOM_WINDOW_OFFSET;
    float TERMINAL_Y_START = (float)Window::windowHeight - (BOTTOM_WINDOW_OFFSET-TERMINAL_MONACO_HEIGHT_LINE_OF_TEXT);
    int showUnderscore = 0;
    static float TERMINAL_INIT_X_OFFSET;
    static float UNDERSCORE_Y_OFFSET;
    static float TEXT_OFFSET;
    float TERMINAL_Y_LINE_SPACING = 3;
    float TERMINAL_LINE_VERTICAL_OFFSET = TERMINAL_MONACO_HEIGHT_LINE_OF_TEXT + TERMINAL_Y_LINE_SPACING;

    LiveTerminalRenderSystem();
    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;

    void onTerminalRender(TerminalTextUpdateEvent& event);

    void onTakingInputFlip(TakingInputFlipEvent& event);

    void renderUnderscore(const std::shared_ptr<Renderer> &sharedPtr);

    void renderLiveLine(const std::shared_ptr<Renderer> &renderer);

    void renderHistoricLines(const std::shared_ptr<Renderer> &renderer);

    void renderAuthoredCommand(const std::shared_ptr<Renderer> &renderer, float lineCount,
                               AuthoredCommand authoredCommand) const;
};


#endif //TEXTBASED_LIVETERMINALRENDERSYSTEM_H
