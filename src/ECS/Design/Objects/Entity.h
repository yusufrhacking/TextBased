#ifndef TEXTBASED_ENTITY_H
#define TEXTBASED_ENTITY_H
#include <spdlog/spdlog.h>
//#include "../Managers/ECSManager.h"

class Entity {
private:
    int id;

public:
    explicit Entity(int id){
        this->id = id;
    }

    Entity() = default;

    Entity(const Entity& entity) = default;

    int getId() const;

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

//    ECSManager* ecsManager;

//    friend bool operator== (const Entity& e1, const Entity& e2){
//        return e1.id == e2.id;
//    }
};


#endif //TEXTBASED_ENTITY_H
