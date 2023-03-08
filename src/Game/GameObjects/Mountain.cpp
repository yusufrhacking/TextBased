#include "Mountain.h"

Mountain::Mountain() {
    loadMountainText();
    entity = manager->createEntity();
    manager->addComponentToEntity<TransformComponent>(entity, std::make_shared<Position>(500, 500));
    manager->addComponentToEntity<SpriteComponent>(entity, text);
}

void Mountain::loadMountainText() {
    text = "";
    text.append("                       Mtn\n");
    text.append("                    Mountain\n");
    text.append("                MountainMountain\n");
    text.append("            MountainMountainMountain\n");
    text.append("        MountainMountainMountainMountain\n");
    text.append("    MountainMountainMountainMountainMountain\n");
    text.append("MountainMountainMountainMountainMountainMountain\n");
}
