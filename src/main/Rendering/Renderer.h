#ifndef TEXTBASED_RENDERER_H
#define TEXTBASED_RENDERER_H
#include <gmock/gmock.h>


#include "../Text/TextComponent.h"
#include "GenericStyleComponent.h"
#include "../Camera/Camera.h"
#include "../Middlemarch/NovelTextComponent.h"

class Renderer {
    public:
        virtual ~Renderer() = default;
        virtual void renderDynamicText(Camera camera, Position position, const TextComponent& sprite, const GenericStyleComponent& style) = 0;
        virtual void renderFixedText(Position position, const TextComponent& sprite, const GenericStyleComponent& style) = 0;
        virtual void renderPresent() = 0;
        virtual void renderClear() = 0;
        virtual void renderTerminal(std::string text) = 0;
        virtual void renderNovelText(Camera camera, Position position, const TextComponent &sprite, const NovelTextComponent &style) = 0;


};

class MockRenderer : public Renderer {
public:
    MOCK_METHOD(void, renderDynamicText, (Camera camera, Position position, const TextComponent& sprite, const GenericStyleComponent& style), (override));
    MOCK_METHOD(void, renderPresent, (), (override));
};



#endif //TEXTBASED_RENDERER_H
