#ifndef TEXTBASED_FRAMEFACTORY_H
#define TEXTBASED_FRAMEFACTORY_H


#include "FrameMap.h"

class FrameFactory {
private:
    std::shared_ptr<FrameMap> frameMap;
public:
    FrameFactory(std::shared_ptr<FrameMap> frameMap);
    std::unique_ptr<Frame> generateFrame(Biome biome, Position gameReferencePosition);
};


#endif //TEXTBASED_FRAMEFACTORY_H
