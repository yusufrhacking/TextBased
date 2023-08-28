#ifndef TEXTBASED_CANONSYSTEM_H
#define TEXTBASED_CANONSYSTEM_H
#include "../../Design/Objects/System.h"
#include "../../../TheCanon/Canon.h"

class CanonSystem: public System {
    Canon& canon;
public:
    explicit CanonSystem(Canon &canon);

    void placeAllEntities();

    void placeEntity(Entity entity);

    void update();

    void placeEntities(std::vector<Entity> vector1);
};


#endif //TEXTBASED_CANONSYSTEM_H
