#ifndef TEXTBASED_FRAMEMAP_H
#define TEXTBASED_FRAMEMAP_H
#include "../../../Helpers/Objects/Position.h"
#include "../Frame/Frame.h"
#include "../../GameSystems/Window/Window.h"
#include <vector>


class FrameMap {
    //Need to make it that frames can only be created here, so that I can track it that way
    //Perhaps store all the frames in this folder, and then make it protected so nobody else can call the constructors?
    //Will interact a lot with the MapGenerationSystem
private:
    int frameWidth = Window::windowWidth;
    int frameHeight = Window::windowHeight;
    std::vector<std::vector<Frame>> frameMap;
    Position startingPosition;
    int startingFrameLocationX;
    int startingFrameLocationY;


public:
    //Will create the initial frame, and perhaps surrounding frames (or leave this to what is called in the update)
    explicit FrameMap(Position startingPosition);

    bool isFrameAtPositionFilled(Position position);

    Frame& getFrame(Position position);

    void surroundLocation(Position playerPosition);

    //void surroundLocation(Position playerLocation); --> this is called in the MapGenerationSystem, like every frame
    //Will seed the 8 locations
    int getXIndexFromPosition(float xPos);

    int getYIndexFromPosition(float yPos);
};


#endif //TEXTBASED_FRAMEMAP_H
