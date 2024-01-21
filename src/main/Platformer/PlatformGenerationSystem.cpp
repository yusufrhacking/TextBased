#include "PlatformGenerationSystem.h"

#include "TextStepPrefab.h"
#include "../MainPlayer/MainPlayerComponent.h"
#include "../Middlemarch/SubjectComponent.h"
#include "../PositionsAndMovement/CollisionEvent.h"

extern std::unique_ptr<EventBus> eventBus;

PlatformGenerationSystem::PlatformGenerationSystem(Position startPosition, std::vector<std::string> stepStrs):
startPosition(startPosition), stepStrs(std::move(stepStrs)){
    nextStepPos = startPosition;
    nextStepPos = nextStepPos - stepJump;

    createNextStep(this->stepStrs[stepInd]);
    listenToEvents();
}

void PlatformGenerationSystem::createNextStep(const std::string& nextStepStr) {
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
    ecsManager->addComponentToEntity<GenericStyleComponent>(nextStepPrefab.entity);
    entities.push_back(nextStepPrefab.entity);
    prevWordX = static_cast<float>(TextComponent::getSurfaceSize(nextStepStr).width);
}

void PlatformGenerationSystem::listenToEvents() {
    eventBus->listenToEvent<CollisionEvent>(this, &PlatformGenerationSystem::screenCollisionForLanding);
}

void PlatformGenerationSystem::screenCollisionForLanding(CollisionEvent& event){
    if (ecsManager->hasComponent<PlatformComponent>(event.a)) {
        if (ecsManager->hasComponent<SubjectComponent>(event.b)) {
            if (stepInd > 0 && entities.size() > stepInd - 1) {
                if (event.a != entities[stepInd - 1]) {
                    stepInd++;
                    createNextStep(stepStrs[stepInd]);
                }
            } else {
                stepInd++;
                createNextStep(stepStrs[stepInd]);
            }
        }
    }
    if (ecsManager->hasComponent<PlatformComponent>(event.b)) {
        if (ecsManager->hasComponent<SubjectComponent>(event.a)) {
            if (stepInd > 0 && entities.size() > stepInd - 1) {
                if (event.b != entities[stepInd - 1]) {
                    stepInd++;
                    createNextStep(stepStrs[stepInd]);
                }
            } else {
                stepInd++;
                createNextStep(stepStrs[stepInd]);
            }
        }
    }
}
