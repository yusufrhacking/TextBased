#ifndef TEXTBASED_VERTICALFORESTFRAME_H
#define TEXTBASED_VERTICALFORESTFRAME_H
#include "ForestFrame.h"

class VerticalForestFrame: public ForestFrame {
public:
    VerticalForestFrame(Position referencePosition);
private:
    void createForests();
};


#endif //TEXTBASED_VERTICALFORESTFRAME_H
