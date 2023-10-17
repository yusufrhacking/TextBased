#ifndef TEXTBASED_BASICLEVEL_H
#define TEXTBASED_BASICLEVEL_H
#include "../HighLevel/ECSManager.h"
#include <memory>
#include "../Woodworking/TreeComponent.h"


extern std::unique_ptr<ECSManager> ecsManager;

class BasicLevel {
public:
    BasicLevel(Position startingPosition);

private:
    Position startingPosition;
    void createPlayer();
    Entity witt;

    void createTree();

    void createLetter(char letter, Position position);

    void createAbyz();
};


#endif //TEXTBASED_BASICLEVEL_H
