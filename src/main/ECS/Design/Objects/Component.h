#ifndef TEXTBASED_COMPONENT_H
#define TEXTBASED_COMPONENT_H

//Ensures component types have unique IDs
struct GenericComponent {
protected:
    static int nextId;
};

//IDs should be for types of components, not individual components
template <typename T>
class Component: public GenericComponent {
public:
    static int getId(){
        nextId++;
        static auto newId = nextId;
        return newId;
    }
};


#endif
