#include "JumpingSystem.h"

#include "JumpingComponent.h"
#include "../TextInput/GameKeyEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../MainPlayer/UnprocessedMovement.h"
#include "../MainPlayer/MovementSystem.h"
#include "../PositionsAndMovement/VelocityComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;



JumpingSystem::JumpingSystem() {
    requireComponent<VelocityComponent>();
    requireComponent<JumpingComponent>();
    requireComponent<LiveComponent>();
    eventBus->listenToEvent<GameKeyEvent>(this, &JumpingSystem::onKeyPressed);
}

void JumpingSystem::update() {
    for(auto i: jumps) {
        auto& velocity = ecsManager->getComponentFromEntity<VelocityComponent>(i.entity).velocity;
        velocity.y = i.jump.y;
        ecsManager->getComponentFromEntity<JumpingComponent>(i.entity).onGround = false;
    }
    jumps.clear();
}

void JumpingSystem::onKeyPressed(GameKeyEvent& event) {
    for (auto entity: getRelevantEntities()) {
        if (!ecsManager->getComponentFromEntity<JumpingComponent>(entity).onGround) {
            continue;
        }
        auto jumpHeight = ecsManager->getComponentFromEntity<JumpingComponent>(entity).jumpSpeed;
        switch (event.getKey()) {
            case GameKey::MOVE_UP:
                jumps.emplace_back(entity, Velocity(0, -jumpHeight));
                break;
            default:
                break;
        }
    }
}

