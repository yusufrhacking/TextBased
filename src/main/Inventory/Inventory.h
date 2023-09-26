#ifndef TEXTBASED_INVENTORY_H
#define TEXTBASED_INVENTORY_H

struct Inventory{
private:
    std::vector<Entity> items;
public:
    [[nodiscard]] std::vector<Entity>& getItems(){
        return items;
    }
    void addItem(Entity item){
        items.push_back(item);
    }
};

#endif //TEXTBASED_INVENTORY_H
