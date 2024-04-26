#ifndef TEXTBASED_PROPOSITIONCOMPONENT_H
#define TEXTBASED_PROPOSITIONCOMPONENT_H

enum class TractatusLayer{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN
};

struct PropositionComponent{
    TractatusLayer layer;
    PropositionComponent() = default;
    explicit PropositionComponent(TractatusLayer layer): layer(layer){}
};

#endif //TEXTBASED_PROPOSITIONCOMPONENT_H
