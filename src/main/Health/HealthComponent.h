#ifndef TEXTBASED_HEALTHCOMPONENT_H
#define TEXTBASED_HEALTHCOMPONENT_H

struct HealthComponent{
    HealthComponent() = default;
    int initialHealth;
    int health;
    explicit HealthComponent(int health): health(health), initialHealth(health){}
};

#endif //TEXTBASED_HEALTHCOMPONENT_H
