#ifndef TEXTBASED_INVENTORY_H
#define TEXTBASED_INVENTORY_H

#include "../Creation/Item.h"

struct Inventory{
    //Need Items, and I need Entities; the entities are the underlying thing
    //Map of Items to vectors of entities?
private:
    std::unordered_map<Item, std::set<Entity>> inventory;
public:

    std::unordered_map<Item, std::set<Entity>> getInventory() const{
        return inventory;
    }

    void addItem(Item item, Entity entity){
        inventory[item].insert(entity);
    }

    void removeEntity(Item item, Entity entity){
        inventory[item].erase(entity);
    }

    bool hasItems(Item item) {
        return !inventory[item].empty();
    }

    Entity removeAnItem(Item item) {
        auto entity = *inventory[item].begin();
        inventory[item].erase(entity);
        return entity;
    }
};

#endif //TEXTBASED_INVENTORY_H
