#ifndef TEXTBASED_FRAMEGENERATOR_H
#define TEXTBASED_FRAMEGENERATOR_H
#include <memory>
#include "FrameMap.h"
#include "OpenPathsSignature.h"

class FrameGenerator {
    std::shared_ptr<FrameMap> frameMap;

public:
    explicit FrameGenerator(std::shared_ptr<FrameMap> frameMap);
    void generateFrame(MapPosition nextFrameMapPosition);
private:
    void createFrame(FrameCell &newFrameCell);
    OpenPathsSignature getOpenPathsSignature(FrameCell& cell);
    std::unique_ptr<Frame> frameFactory(std::bitset<4> openPathsSignature, Biome biome);
};


#endif //TEXTBASED_FRAMEGENERATOR_H
