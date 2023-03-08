#ifndef TEXTBASED_TREE_H
#define TEXTBASED_TREE_H
#include "GameObject.h"

class Tree: public GameObject {
public:
    Tree(Position starterPosition);

private:
    void loadTreeText();

    static std::string getXOffCenterOffset(int diff);
    Position getRenderPosition(Position anchorPosition);
    WindowNum getHeightOffset();
};


#endif //TEXTBASED_TREE_H
