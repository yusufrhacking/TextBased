#include "TextGenerator.h"

std::string TextGenerator::getTreeText() {
    std::string centerOffset = "        ";
    return centerOffset + "Tree"
           + "\n" + getXOffCenterOffset(2, centerOffset) + "TreeTree"
           + "\n" + getXOffCenterOffset(4, centerOffset) + "TreeTreeTree"
           + "\n" + getXOffCenterOffset(6, centerOffset) + "TreeTreeTreeTree"
           + "\n" + getXOffCenterOffset(8, centerOffset) + "TreeTreeTreeTreeTree"
           + "\n" + centerOffset + "Tree"
           + "\n" + centerOffset + "Tree"
           + "\n" + centerOffset + "Tree"
           + "\n" + centerOffset + "Tree"
           + "\n" + centerOffset + "Tree"
           + "\n" + centerOffset + "Tree";
}


std::string TextGenerator::getMountainText() {
    std::string text;
    text.append("                       Mtn\n");
    text.append("                    Mountain\n");
    text.append("                MountainMountain\n");
    text.append("            MountainMountainMountain\n");
    text.append("        MountainMountainMountainMountain\n");
    text.append("    MountainMountainMountainMountainMountain\n");
    text.append("MountainMountainMountainMountainMountainMountain\n");
    return text;
}

std::string TextGenerator::getWelcomeText() {
    std::string text;
    text.append("          WELCOME TO BABYLON\n");
    text.append("PROCEED FORWARDS TO BEGIN YOUR JOURNEY\n");
}

std::string TextGenerator::getXOffCenterOffset(int diff, std::string centerOffset){
    std::string newOffset;
    for (int space=0; space < centerOffset.size() - diff; space++){
        newOffset.append(" ");
    }
    return newOffset;
}


