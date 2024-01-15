#include "PlatformGenerationSystem.h"

#include "TextStepPrefab.h"

PlatformGenerationSystem::PlatformGenerationSystem(Position startPosition, std::vector<std::string> stepStrs) {
    this->startPosition = startPosition;
    Position nextStepPos = startPosition;
    nextStepPos = nextStepPos - stepJump;

    // for (const auto& nextStepStr : stepStrs) {
    createNextStep(nextStepPos, stepStrs[stepInd]);
    // }
}

void PlatformGenerationSystem::createNextStep(Position& nextStepPos, const std::string& nextStepStr) {
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
    prevWordX = static_cast<float>(TextComponent::getSurfaceSize(nextStepStr).width);
}
