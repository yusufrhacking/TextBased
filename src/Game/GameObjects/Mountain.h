#ifndef TEXTBASED_MOUNTAIN_H
#define TEXTBASED_MOUNTAIN_H

#include <string>
#include "GameObject.h"

class Mountain: public GameObject {

public:
    Mountain();

private:
    void loadMountainText();
};


#endif //TEXTBASED_MOUNTAIN_H
