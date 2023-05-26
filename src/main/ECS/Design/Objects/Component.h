#ifndef TEXTBASED_COMPONENT_H
#define TEXTBASED_COMPONENT_H

#include "../../Components/TextComponents/TextComponent.h"
#include <memory>

//Ensures component types have unique IDs
struct GenericComponent {
protected:
    static int nextId;
};

//IDs should be for types of components, not individual components
template<typename T>
class Component : public GenericComponent {
public:
    static int getId(){
        static auto newId = nextId++;
        return newId;
    }
};


#endif
