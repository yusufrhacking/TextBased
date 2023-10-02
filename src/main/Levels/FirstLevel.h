#ifndef TEXTBASED_FIRSTLEVEL_H
#define TEXTBASED_FIRSTLEVEL_H
#include "../HighLevel/ECSManager.h"
#include <memory>
#include "../Woodworking/TreeComponent.h"


extern std::unique_ptr<ECSManager> ecsManager;

class FirstLevel {
public:
    FirstLevel(Position startingPosition);

private:
    Position startingPosition;
    void createPlayer();
    Entity witt;

    void createTree();

    void createLetter(char letter, Position position);

    void createAbyz();
};


#endif //TEXTBASED_FIRSTLEVEL_H
