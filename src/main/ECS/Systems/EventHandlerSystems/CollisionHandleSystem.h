#ifndef TEXTBASED_COLLISIONHANDLESYSTEM_H
#define TEXTBASED_COLLISIONHANDLESYSTEM_H

#include "EventConsumerSystem.h"
#include "../../Components/CollisionComponent.h"
#include "../../../Helpers/EventSystem/Events/CollisionEvent.h"

class CollisionHandleSystem: public EventConsumerSystem {
public:
    explicit CollisionHandleSystem(std::shared_ptr<EventBus> eventBus) {
        requireComponent<CollisionComponent>();
        listenToEvents(eventBus);
    }

    void listenToEvents(std::shared_ptr<EventBus> eventBus);

    void onCollision(CollisionEvent& event);

    void update(std::shared_ptr<EventBus> eventBus) override;
};


#endif //TEXTBASED_COLLISIONHANDLESYSTEM_H
