#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"
#include "TextPerson.h"
#include <utility>

extern std::unique_ptr<ECSManager> manager;

TextPerson::TextPerson() {
    this->text = "Robert C. Martin";
    this->entity = manager->createEntity();
    setUpTextPerson();
}

TextPerson::TextPerson(const std::string& text) {
    this->text = text;
    this->entity = manager->createEntity();
    setUpTextPerson();
}

void TextPerson::setUpTextPerson(){
    manager->addComponentToEntity<PositionComponent>(entity, std::make_shared<Position>(50, 50));
    manager->addComponentToEntity<MovementComponent>(entity, std::make_shared<Velocity>(20, 1));
    manager->addComponentToEntity<SpriteComponent>(entity, text);
}

#pragma clang diagnostic pop