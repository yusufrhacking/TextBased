#ifndef TEXTBASED_ENTITY_H
#define TEXTBASED_ENTITY_H


class Entity {
private:
    int id;

public:
    explicit Entity(int id){
        this->id = id;
    }

    int getId() const;
};


#endif //TEXTBASED_ENTITY_H
