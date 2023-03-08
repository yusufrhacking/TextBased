#ifndef TEXTBASED_TREE_H
#define TEXTBASED_TREE_H
#include "GameObject.h"

class Tree: public GameObject {
public:
    explicit Tree(Position starterPosition);

private:
    void loadTreeText();

    static std::string getXOffCenterOffset(int diff);
};


#endif //TEXTBASED_TREE_H
