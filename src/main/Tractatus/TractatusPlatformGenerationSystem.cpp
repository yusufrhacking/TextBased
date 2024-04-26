#include "TractatusPlatformGenerationSystem.h"
#include "../EventSystem/EventBus.h"

#include "../Platformer/TextStepPrefab.h"
#include "../MainPlayer/MainPlayerComponent.h"
#include "../Middlemarch/SubjectComponent.h"
#include "../PositionsAndMovement/CollisionEvent.h"
#include "../Platformer/PlatformComponent.h"
#include "PropositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

extern std::unique_ptr<EventBus> eventBus;

TractatusPlatformGenerationSystem::TractatusPlatformGenerationSystem(Position startPosition, std::vector<std::string> stepStrs):
        startPosition(startPosition), stepStrs(std::move(stepStrs)){
    nextStepPos = startPosition;
    nextStepPos = nextStepPos - stepJump;

    createNextStep(this->stepStrs[stepInd]);
    listenToEvents();
}

void TractatusPlatformGenerationSystem::createNextStep(const std::string& nextStepStr) {
    if(direction == -1) {
        prevWordX = static_cast<float>(TextComponent::getSurfaceSize(nextStepStr).width);
    }
    nextStepPos.x += (stepJump.x + prevWordX) * direction;
    nextStepPos.y += stepJump.y;
    if (nextStepPos.x + TextComponent::getSurfaceSize(nextStepStr).width > Window::deriveRelativeBottomRight(startPosition).x) {
        nextStepPos.x -= stepJump.x * 2;
        nextStepPos.x -= prevWordX;
        nextStepPos.x -= static_cast<float>(TextComponent::getSurfaceSize(nextStepStr).width);
        direction = -1;
    }
    TextStepPrefab nextStepPrefab{nextStepStr, nextStepPos};
    ecsManager->addComponentToEntity<PropositionComponent>(nextStepPrefab.entity, TractatusLayer::ONE);
    entities.push_back(nextStepPrefab.entity);
    prevWordX = static_cast<float>(TextComponent::getSurfaceSize(nextStepStr).width);
}

void TractatusPlatformGenerationSystem::listenToEvents() {
    eventBus->listenToEvent<CollisionEvent>(this, &TractatusPlatformGenerationSystem::screenCollisionForLanding);
}

void TractatusPlatformGenerationSystem::screenCollisionForLanding(CollisionEvent& event){
    if (ecsManager->hasComponent<PlatformComponent>(event.a)) {
        if (ecsManager->hasComponent<SubjectComponent>(event.b)) {
            if(ecsManager->getComponentFromEntity<PlatformComponent>(event.a).beenReached) {
                return;
            }
            ecsManager->getComponentFromEntity<PlatformComponent>(event.a).beenReached = true;
            stepInd++;
            createNextStep(stepStrs[stepInd]);
        }
    }
    if (ecsManager->hasComponent<PlatformComponent>(event.b)) {
        if (ecsManager->hasComponent<SubjectComponent>(event.a)) {
            if(ecsManager->getComponentFromEntity<PlatformComponent>(event.b).beenReached) {
                return;
            }
            ecsManager->getComponentFromEntity<PlatformComponent>(event.b).beenReached = true;
            stepInd++;
            createNextStep(stepStrs[stepInd]);
        }
    }
}