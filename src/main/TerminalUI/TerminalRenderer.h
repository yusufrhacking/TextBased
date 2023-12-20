#ifndef TEXTBASED_TERMINALRENDERER_H
#define TEXTBASED_TERMINALRENDERER_H

#include <memory>
#include "../Rendering/Renderer.h"


class TerminalRenderer {
private:
    Camera unusedCamera{Position{0,0}};
    int showUnderscore = 0;
    int typedTextInd = 0;
    std::chrono::steady_clock::time_point lastUnderscoreToggleTime;
    int underscoreToggleDelayMilliseconds;
    bool underscoreVisible;

public:
    TerminalRenderer(): underscoreToggleDelayMilliseconds(500), underscoreVisible(true) {
        lastUnderscoreToggleTime = std::chrono::steady_clock::now();
    }

    Position renderAuthor(const std::shared_ptr<Renderer> &renderer, Position startingPosition,
                          const std::string& authorStr, StyleComponent style);

    Position renderPromptSymbol(const std::shared_ptr<Renderer> &renderer, Position startingPosition, StyleComponent style);

    Position renderText(const std::shared_ptr<Renderer> &renderer, Position startingPosition,
                        const std::string& currText, StyleComponent style);

    Position renderUnderscore(const std::shared_ptr<Renderer> &renderer, Position startingPosition,
                              const std::string& currText, bool isTerminalLive, StyleComponent style);
};


#endif //TEXTBASED_TERMINALRENDERER_H
