#ifndef TEXTBASED_UIRENDERSYSTEM_H
#define TEXTBASED_UIRENDERSYSTEM_H
#include "../ECSObjects/System.h"
#include "Renderer.h"
#include "../TextInput/TextQueuedEvent.h"

class UIRenderSystem: public System {
public:
    std::shared_ptr<Renderer> renderer;
    explicit UIRenderSystem(std::shared_ptr<Renderer>& renderer);
private:
    void listenToEvents();
    void onTextQueuedEvent(TextQueuedEvent& event);
};


#endif //TEXTBASED_UIRENDERSYSTEM_H
