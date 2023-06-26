#ifndef TEXTBASED_RENDERER_H
#define TEXTBASED_RENDERER_H
#include <gmock/gmock.h>


#include "../../../ECS/Components/TextComponents/TextComponent.h"
#include "../../../ECS/Components/StyleComponent.h"
#include "../Camera/Camera.h"

class Renderer {
    public:
        virtual ~Renderer() = default;
        virtual void renderText(Camera camera, Position position, const TextComponent& sprite, const StyleComponent& style) = 0;
        virtual void renderFrame() = 0;

};

class MockRenderer : public Renderer {
public:
    MOCK_METHOD(void, renderText, (Camera camera, Position position, const TextComponent& sprite, const StyleComponent& style), (override));
    MOCK_METHOD(void, renderFrame, (), (override));
};



#endif //TEXTBASED_RENDERER_H
