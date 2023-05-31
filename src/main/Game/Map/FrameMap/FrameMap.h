#ifndef TEXTBASED_FRAMEMAP_H
#define TEXTBASED_FRAMEMAP_H
#include "../../../Helpers/Objects/Position.h"
#include "../Frame/Frame.h"
#include "../../GameSystems/Window/Window.h"
#include "FrameCell.h"
#include "../../../Helpers/Objects/MapPosition.h"
#include <vector>


class FrameMap {
    //Need to make it that frames can only be created here, so that I can track it that way
    //Perhaps store all the frames in this folder, and then make it protected so nobody else can call the constructors?
    //Will interact a lot with the MapGenerationSystem

    //Data structure should be like a matrix, let's say 10k x 10k, and then if it goes beyond that, 2x that dimension
    //Frames will track what entities are inside them, this will need a system to keep track of this too
    //requireComponent<MovementComponent> --> needs polymorphic components too
    //Check ALL entities at the beginning, and then require position/movement components so the update tracks those
private:
    static const int numRows = 10000;
    static const int numCols = 10000;
    FrameCell startingFrame;
    std::vector<std::vector<FrameCell>> frameMap;
    Position startingPosition;
    MapPosition startingMapPosition;
    int frameWidth = Window::windowWidth;
    int frameHeight = Window::windowHeight;



public:
    //Will create the initial frame, and perhaps surrounding frames (or leave this to what is called in the update)
    explicit FrameMap(Position startingPosition);

    bool isFrameAtPositionFilled(Position position);

    Frame& getFrame(Position position);

    void surroundLocation(Position playerPosition);

    MapPosition getMapPositionFromGamePosition(Position playerPosition);


    //void surroundLocation(Position playerLocation); --> this is called in the MapGenerationSystem, like every frame
    //Will seed the 8 locations
    Position getGamePositionFromMapPosition(MapPosition mapPosition);
};


#endif //TEXTBASED_FRAMEMAP_H
