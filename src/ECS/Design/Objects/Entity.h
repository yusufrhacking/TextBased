#ifndef TEXTBASED_ENTITY_H
#define TEXTBASED_ENTITY_H
#include <spdlog/spdlog.h>

class Entity {
private:
    int id;

public:
    explicit Entity(int id){
        this->id = id;
    }

    Entity() = default;

    Entity(const Entity& entity) = default;

    [[nodiscard]] int getId() const;

    Entity& operator = (const Entity& other) = default;

    bool operator == (const Entity& other) const {
        return id == other.id;
    }

    bool operator != (const Entity& other) const {
        return id != other.id;
    }

    bool operator < (const Entity& other) const{
        return id < other.id;
    }
};


#endif
