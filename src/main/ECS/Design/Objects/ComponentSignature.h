#ifndef TEXTBASED_COMPONENTSIGNATURE_H
#define TEXTBASED_COMPONENTSIGNATURE_H
#include <bitset>
#include "Component.h"

const unsigned int MAX_COMPONENTS = 64;

class ComponentSignature {
    std::bitset<MAX_COMPONENTS> signature;
public:
    ComponentSignature() = default;

    [[nodiscard]] bool test(int index) const;

    void set(int index);

    void set(int index, bool flag);

    void reset();

    [[nodiscard]] std::bitset<MAX_COMPONENTS> getSignature() const;

    [[nodiscard]] bool matches(ComponentSignature otherSignature) const;

    static bool systemHoldsEntity(ComponentSignature systemSignature, ComponentSignature entitySignature);

    template <typename TComponent>
    [[nodiscard]] bool test() const;

    template <typename TComponent>
    void set();

    template <typename TComponent>
    void set(bool flag);
};

template <typename TComponent>
[[nodiscard]] bool ComponentSignature::test() const{

}

template <typename TComponent>
void ComponentSignature::set(){
    if (std::is_base_of<TextComponent, TComponent>::value){
        signature.set(Component<TextComponent>::getId());
    }
    signature.set(Component<TComponent>::getId());
}

template <typename TComponent>
void ComponentSignature::set(bool flag){

}

#endif
