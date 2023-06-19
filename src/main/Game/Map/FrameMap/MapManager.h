#ifndef TEXTBASED_MAPMANAGER_H
#define TEXTBASED_MAPMANAGER_H
#include "../../../Helpers/Objects/Position.h"
#include "../Frame/Frame.h"
#include "../../GameSystems/Window/Window.h"
#include "FrameCell.h"
#include "../../../Helpers/Objects/MapPosition.h"
#include "FrameMap.h"
#include "FrameGenerator.h"
#include <vector>

class MapManager {
    //Need to make it that frames can only be created here, so that I can track it that way
    //Perhaps store all the frames in this folder, and then make it protected so nobody else can call the constructors?
    //Will interact a lot with the MapGenerationSystem

    //Data structure should be like a matrix, let's say 10k x 10k, and then if it goes beyond that, 2x that dimension
    //Frames will track what entities are inside them, this will need a system to keep track of this too
    //requireComponent<MovementComponent> --> needs polymorphic components too
    //Check ALL entities at the beginning, and then require position/movement components so the update tracks those
private:
    std::shared_ptr<FrameMap> frameMap;
    FrameGenerator frameGenerator;
    MapPosition startingMapPosition;
    int frameWidth = Window::windowWidth;
    int frameHeight = Window::windowHeight;
    MapPosition positionAdjustment;

    void frameCellAtPosition(FrameCell& playerCell, FrameCell& newCell);


public:
    //Will create the initial frame, and perhaps surrounding frames (or leave this to what is called in the update)
    explicit MapManager(Position startingPosition);

    bool isFrameAtPositionFilled(Position position);

    Frame& getFrame(Position position);

    void surroundLocation(Position playerPosition);

    MapPosition getMapPositionFromGamePosition(Position playerPosition);

    //void surroundLocation(Position playerLocation); --> this is called in the MapGenerationSystem, like every frame
    //Will seed the 8 locations
    Position getGamePositionFromMapPosition(MapPosition mapPosition);

    void applyBiomeAcrossRadius(Biome biome, int radius);
};


#endif //TEXTBASED_MAPMANAGER_H
