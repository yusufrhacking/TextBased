#ifndef SUBJECTRENDERSYSTEM_H
#define SUBJECTRENDERSYSTEM_H
#include "../Rendering/DynamicRenderSystem.h"


class SubjectRenderSystem: public DynamicRenderSystem {
public:
    explicit SubjectRenderSystem();

    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;
};



#endif //SUBJECTRENDERSYSTEM_H
