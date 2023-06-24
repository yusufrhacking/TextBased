#include "FrameFactory.h"
#include "../../Levels/Forest/SouthEastOpenForestFrame.h"

FrameFactory::FrameFactory(std::shared_ptr<FrameMap> frameMap) {

}

std::unique_ptr<Frame> FrameFactory::generateFrame(Biome biome, Position gameReferencePosition) {
    return std::make_unique<SouthEastOpenForestFrame>(gameReferencePosition);
}
