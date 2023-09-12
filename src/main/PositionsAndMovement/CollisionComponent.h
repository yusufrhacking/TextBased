#ifndef TEXTBASED_COLLISIONCOMPONENT_H
#define TEXTBASED_COLLISIONCOMPONENT_H
#include "Size.h"

struct CollisionComponent{
    Size collisionRange{};

    CollisionComponent(){
        collisionRange = {0, 0};
    }

    explicit CollisionComponent(Size surfaceSize){
        collisionRange = {surfaceSize.width, surfaceSize.height};
    }
};

//struct CollisionComponent{
//    RenderedVal widthCollisionRange;
//    RenderedVal heightCollisionRange;
//
//    explicit CollisionComponent(const std::string& text){
//        Size surfaceSize = {static_cast<RenderedVal>
//                            (TextComponent::getTextWidth(text) * MONACO_RENDERED_TEXT_WIDTH_SCALER),
//                            MONACO_HEIGHT_OF_A_LINE_OF_TEXT * TextComponent::getTextHeight(text)};
//        this->widthCollisionRange = surfaceSize.width;
//        this->heightCollisionRange = surfaceSize.height;
//    }
//
//    explicit CollisionComponent(Size surfaceSize){
//        this->widthCollisionRange = surfaceSize.width;
//        this->heightCollisionRange = surfaceSize.height;
//    }
//
//    explicit CollisionComponent(int width = 0, int height = 0){
//        this->widthCollisionRange = width;
//        this->heightCollisionRange = height;
//    }
//};

/*
 * struct CollisionComponent{
    Size collisionRange{};

    explicit CollisionComponent(const std::string& text){
        Size surfaceSize = {static_cast<RenderedVal>
                            (TextComponent::getTextWidth(text) * MONACO_RENDERED_TEXT_WIDTH_SCALER),
                            MONACO_HEIGHT_OF_A_LINE_OF_TEXT * TextComponent::getTextHeight(text)};
        collisionRange = {surfaceSize.width, surfaceSize.height};
    }

    explicit CollisionComponent(Size surfaceSize){
        collisionRange = {surfaceSize.width, surfaceSize.height};
    }
};
 */

#endif
