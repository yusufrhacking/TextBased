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
    int standardTypingDelayMilliseconds = 50;
    int currentWaitingTime = standardTypingDelayMilliseconds;
    int COMMA_MULTIPLIER = 7;
    int subjectInd = 0;

    void readTheText(Entity entity, const std::shared_ptr<Renderer> &renderer);


public:
    NovelTextRenderSystem();
    void render(const std::shared_ptr<Renderer>& renderer) override;

};


#endif //TEXTBASED_NOVELTEXTRENDERSYSTEM_H
