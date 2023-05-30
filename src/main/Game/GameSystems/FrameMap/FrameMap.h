#ifndef TEXTBASED_FRAMEMAP_H
#define TEXTBASED_FRAMEMAP_H


class FrameMap {
    //Need to make it that frames can only be created here, so that I can track it that way
    //Perhaps store all the frames in this folder, and then make it protected so nobody else can call the constructors?
    //Will interact a lot with the MapGenerationSystem

    //void setup(Position startingPosition);
    //Will create the initial frame, and perhaps surrounding frames (or leave this to what is called in the update)

    //Frame getCurrentFrame(Position position);
    //

    //void surroundLocation(Position playerLocation); --> this is called in the MapGenerationSystem, like every frame
    //Will seed the 8 locations
};


#endif //TEXTBASED_FRAMEMAP_H
