#ifndef TEXTBASED_UNPROCESSEDMOVEMENT_H
#define TEXTBASED_UNPROCESSEDMOVEMENT_H


#include "../../../Design/Objects/Entity.h"

struct UnprocessedMovement {
    Entity entity;
    double xChange, yChange;
    UnprocessedMovement(Entity entity, double xChange, double yChange);
};


#endif //TEXTBASED_UNPROCESSEDMOVEMENT_H
