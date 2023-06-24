#ifndef TEXTBASED_FRAMEGENERATOR_H
#define TEXTBASED_FRAMEGENERATOR_H
#include <memory>
#include "FrameMap.h"
#include "OpenPathsSignature.h"
#include "FrameFactory.h"

class FrameGenerator {
    std::shared_ptr<FrameMap> frameMap;
    FrameFactory frameFactory;

public:
    explicit FrameGenerator(std::shared_ptr<FrameMap> frameMap);
    void generateFrame(MapPosition nextFrameMapPosition);
private:
    void createFrame(FrameCell &newFrameCell);
    OpenPathsSignature getOpenPathsSignature(FrameCell& cell);
};


#endif //TEXTBASED_FRAMEGENERATOR_H
