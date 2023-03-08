#include "Tree.h"

std::string Center_Offset = "        ";

Tree::Tree() {
    loadTreeText();
    entity = manager->createEntity();
    Position anchorPosition = window->getBottomLeftPosition();
    double xPos = anchorPosition.xPos;
    double yPos = anchorPosition.yPos - getTextHeight() * (RENDERED_TEXT_HEIGHT+RENDERED_LINE_HEIGHT);
    spdlog::info(anchorPosition.yPos);
    spdlog::info(getTextHeight());
    spdlog::info(yPos);
    manager->addComponentToEntity<PositionComponent>(entity, std::make_shared<Position>(xPos, yPos));
    manager->addComponentToEntity<SpriteComponent>(entity, text);
}

void Tree::loadTreeText() {
    text = Center_Offset + "Tree"
           + "\n" + getXOffCenterOffset(2) + "TreeTree"
           + "\n" + getXOffCenterOffset(4) + "TreeTreeTree"
           + "\n" + getXOffCenterOffset(6) + "TreeTreeTreeTree"
           + "\n" + getXOffCenterOffset(8) + "TreeTreeTreeTreeTree"
           + "\n" + Center_Offset + "Tree"
           + "\n" + Center_Offset + "Tree"
           + "\n" + Center_Offset + "Tree"
           + "\n" + Center_Offset + "Tree"
           + "\n" + Center_Offset + "Tree"
           + "\n" + Center_Offset + "Tree";
}


std::string Tree::getXOffCenterOffset(int diff){
    std::string newOffset;
    for (int space=0; space < Center_Offset.size() - diff; space++){
        newOffset.append(" ");
    }
    return newOffset;

}
