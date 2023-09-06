#ifndef TEXTBASED_WORDCOMPREHENSIONSYSTEM_H
#define TEXTBASED_WORDCOMPREHENSIONSYSTEM_H
#include "../HighLevel/ECSManager.h"
#include "TextCommandEvent.h"
#include "GameKeyEvent.h"
#include "TextInputEvent.h"
#include "../ECSObjects/System.h"

class WordComprehensionSystem: public EntityRenderSystem {
public:
    WordComprehensionSystem();
    void render(std::shared_ptr<Renderer> &renderer);
private:
    std::string text;
    bool listening_to_letters;
    void listenToEvents();
    void onGameKey(GameKeyEvent& event);
    void onText(TextInputEvent& event);
};


#endif //TEXTBASED_WORDCOMPREHENSIONSYSTEM_H
