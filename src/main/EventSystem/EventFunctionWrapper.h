#ifndef TEXTBASED_EVENTFUNCTIONWRAPPER_H
#define TEXTBASED_EVENTFUNCTIONWRAPPER_H

#include "Event.h"
#include <functional>

class IEventFunctionWrapper {
private:
    virtual void call(Event& event) = 0;
public:
    virtual ~IEventFunctionWrapper() = default;
    void execute(Event& event);
};

template <typename TEvent, typename TOwner>
class EventFunctionWrapper: public IEventFunctionWrapper {
private:
    typedef void (TOwner::*FunctionToBeCalled)(TEvent&);

    TOwner* ownerOfFunction;
    FunctionToBeCalled functionToBeCalled;

    void call(Event& event) override;

public:
    EventFunctionWrapper(TOwner* ownerOfFunction, FunctionToBeCalled functionToBeCalled){
        this->ownerOfFunction = ownerOfFunction;
        this->functionToBeCalled = functionToBeCalled;
    }
    ~EventFunctionWrapper() override = default;
};

template<typename TEvent, typename TOwner>
void EventFunctionWrapper<TEvent, TOwner>::call(Event &event) {
    std::invoke(functionToBeCalled, ownerOfFunction, static_cast<TEvent&>(event));
}


#endif
