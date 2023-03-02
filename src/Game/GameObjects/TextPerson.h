#ifndef TEXTBASED_TEXTPERSON_H
#define TEXTBASED_TEXTPERSON_H
#include "../../ECS/Design/Managers/ECSManager.h"
#include "../../ECS/Components/MovementComponent.h"

class TextPerson {
private:
    std::string text;
    Entity entity;

    void setUpTextPerson();

public:
    TextPerson();

    TextPerson(const std::string& text);

    ~TextPerson() = default;

};


#endif //TEXTBASED_TEXTPERSON_H
