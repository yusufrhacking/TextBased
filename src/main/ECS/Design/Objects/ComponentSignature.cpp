#include "ComponentSignature.h"

bool ComponentSignature::test(int index) const {
    return signature.test(index);
}

void ComponentSignature::set(int index) {
    signature.set(index, true);
}

void ComponentSignature::set(int index, bool flag) {
    signature.set(index, flag);
}

void ComponentSignature::reset() {
    signature.reset();
}

bool ComponentSignature::matches(ComponentSignature otherSignature) const {
    return (signature & otherSignature.getSignature()) == signature
    || (otherSignature.getSignature() & signature) == otherSignature.getSignature();
}

std::bitset<MAX_COMPONENTS> ComponentSignature::getSignature() const {
    return signature;
}


