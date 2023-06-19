#ifndef TEXTBASED_FRAMEGENERATOR_H
#define TEXTBASED_FRAMEGENERATOR_H
#include <memory>
#include "FrameMap.h"

class FrameGenerator {
    std::shared_ptr<FrameMap> frameMap;

public:
    explicit FrameGenerator(std::shared_ptr<FrameMap> frameMap);
    void generateFrame(MapPosition nextFrameMapPosition);
private:
    void frameCellAtPosition(FrameCell &newFrameCell);

    std::bitset<4> getOpeningSignature(FrameCell &cell);
};


#endif //TEXTBASED_FRAMEGENERATOR_H
