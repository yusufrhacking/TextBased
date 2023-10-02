#ifndef TEXTBASED_HEALTHCOMPONENT_H
#define TEXTBASED_HEALTHCOMPONENT_H

struct HealthComponent{
    HealthComponent() = default;
    int health;
    explicit HealthComponent(int health): health(health){}
};

#endif //TEXTBASED_HEALTHCOMPONENT_H
