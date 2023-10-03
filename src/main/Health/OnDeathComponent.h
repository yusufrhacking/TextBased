#ifndef TEXTBASED_ONDEATHCOMPONENT_H
#define TEXTBASED_ONDEATHCOMPONENT_H

struct OnDeathComponent{
    std::function<void()> emitEvent;

    explicit OnDeathComponent(std::function<void()> emitEventFunction): emitEvent(std::move(emitEventFunction)) {}

    OnDeathComponent() = default;
};

#endif //TEXTBASED_ONDEATHCOMPONENT_H
