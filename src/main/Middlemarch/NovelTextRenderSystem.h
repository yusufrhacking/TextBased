#ifndef TEXTBASED_NOVELTEXTRENDERSYSTEM_H
#define TEXTBASED_NOVELTEXTRENDERSYSTEM_H

#include <MacTypes.h>
#include "../ECSObjects/System.h"
#include "../Rendering/Renderer.h"
#include "NovelTextComponent.h"
#include "../Rendering/FixedRenderSystem.h"

class NovelTextRenderSystem: public FixedRenderSystem {
private:
    std::string getLinedUpText(const std::string& text);
    std::chrono::steady_clock::time_point lastUpdateTime;
    int typingDelayMilliseconds = 50;

public:
    NovelTextRenderSystem();
    void render(const std::shared_ptr<Renderer>& renderer) override;

};


#endif //TEXTBASED_NOVELTEXTRENDERSYSTEM_H
