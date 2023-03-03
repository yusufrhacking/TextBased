#ifndef TEXTBASED_GAMEOBJECT_H
#define TEXTBASED_GAMEOBJECT_H

#include <string>
#include "../../ECS/Design/Objects/Entity.h"
#include "../../ECS/Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> manager;

class GameObject {
protected:
    std::string text;
    Entity entity;
};

#endif
