#ifndef TEXTBASED_INVENTORY_H
#define TEXTBASED_INVENTORY_H

#include "../Creation/Item.h"

struct Inventory{
private:
    std::unordered_map<Item, std::set<Entity>> inventory;
    int inventoryAvailableItemSize = 0;
public:

    [[nodiscard]] std::unordered_map<Item, std::set<Entity>> getInventory() const{
        return inventory;
    }

    void addItem(Item item, Entity entity){
        if (inventory[item].empty()){
            inventoryAvailableItemSize++;
        }
        inventory[item].insert(entity);
    }

    void removeEntity(Item item, Entity entity){
        inventory[item].erase(entity);
        if (inventory[item].empty()){
            inventoryAvailableItemSize--;
        }
    }

    bool hasItems(Item item) {
        return !inventory[item].empty();
    }

    Entity removeAnItem(Item item) {
        auto entity = *inventory[item].begin();
        inventory[item].erase(entity);
        if (inventory[item].empty()){
            inventoryAvailableItemSize--;
        }
        return entity;
    }

    int getUsedSize() const{
        return inventoryAvailableItemSize;
    }
};

#endif //TEXTBASED_INVENTORY_H
