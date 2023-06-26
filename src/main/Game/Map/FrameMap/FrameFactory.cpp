#include "FrameFactory.h"

#include <utility>
#include "../../Levels/Forest/SouthEastOpenForestFrame.h"
#include "../../Levels/Forest/SouthOpenForestFrame.h"

FrameFactory::FrameFactory(std::shared_ptr<FrameMap> frameMap): frameMap(std::move(frameMap)) {

}

std::unique_ptr<Frame> FrameFactory::generateFrame(OpenAt frameConfiguration, Biome biome, Position gameReferencePosition) {
    return std::make_unique<SouthOpenForestFrame>(gameReferencePosition);
}
