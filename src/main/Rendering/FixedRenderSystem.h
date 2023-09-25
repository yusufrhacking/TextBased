#ifndef TEXTBASED_FIXEDRENDERSYSTEM_H
#define TEXTBASED_FIXEDRENDERSYSTEM_H

#include "DynamicRenderSystem.h"
struct FixedRenderSystem: public System{
    virtual void render(const std::shared_ptr<Renderer>& renderer) = 0;
};

#endif
