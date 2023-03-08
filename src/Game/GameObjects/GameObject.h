#ifndef TEXTBASED_GAMEOBJECT_H
#define TEXTBASED_GAMEOBJECT_H

#include <string>
#include "../../ECS/Design/Objects/Entity.h"
#include "../../ECS/Design/Managers/ECSManager.h"
#include "../../Objects/Size.h"
#include <sstream>

extern std::unique_ptr<ECSManager> manager;

class GameObject {
protected:
    std::string text;
    Entity entity;
    int textWidth;
    int textHeight;

    int findTextWidth();
    int getTextHeight();

    Position getRenderPosition(Position anchorPosition);
    WindowNum getHeightOffset();
};

#endif
