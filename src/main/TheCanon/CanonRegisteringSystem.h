#ifndef TEXTBASED_CANONREGISTERINGSYSTEM_H
#define TEXTBASED_CANONREGISTERINGSYSTEM_H
#include "Canon.h"
#include "../ECSObjects/System.h"

class CanonRegisteringSystem: public System {
public:
    Canon& canon;

    explicit CanonRegisteringSystem(Canon &canon);

    void placeAllEntities();

    void placeEntity(Entity entity);

    void update();

    void placeEntities(std::vector<Entity> vector1);
};


#endif //TEXTBASED_CANONREGISTERINGSYSTEM_H
