#ifndef TEXTBASED_INVENTORY_H
#define TEXTBASED_INVENTORY_H

struct Inventory{
private:
    std::vector<Entity> items;
public:
    [[nodiscard]] std::vector<Entity> getItems() const&{
        return items;
    }
    void addItem(Entity item){
        items.push_back(item);
    }

    void removeItemAt(std::vector<Entity>::iterator position) {
        if (position != items.end()) {
            items.erase(position);
        }
    }

};

#endif //TEXTBASED_INVENTORY_H
