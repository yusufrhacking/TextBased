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
};


#endif
