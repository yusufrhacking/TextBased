#ifndef TEXTBASED_NOVELTEXTRENDERSYSTEM_H
#define TEXTBASED_NOVELTEXTRENDERSYSTEM_H

#include <MacTypes.h>
#include "../ECSObjects/System.h"
#include "../Rendering/Renderer.h"
#include "NovelTextComponent.h"
#include "../Rendering/FixedRenderSystem.h"

class NovelTextRenderSystem: public FixedRenderSystem {
private:
    std::string getLinedUpText(const TextComponent& textComponent);

public:
    NovelTextRenderSystem();
    void render(const std::shared_ptr<Renderer>& renderer) override;

};


#endif //TEXTBASED_NOVELTEXTRENDERSYSTEM_H
