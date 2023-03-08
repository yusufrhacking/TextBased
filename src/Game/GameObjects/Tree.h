#ifndef TEXTBASED_TREE_H
#define TEXTBASED_TREE_H
#include "GameObject.h"

class Tree: public GameObject {
public:
    explicit Tree(Position starterPosition);
    static std::string getTreeText();

private:
    static std::string getXOffCenterOffset(int diff);
};


#endif //TEXTBASED_TREE_H
