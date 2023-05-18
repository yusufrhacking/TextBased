#ifndef TEXTBASED_EVENTCALLBACK_H
#define TEXTBASED_EVENTCALLBACK_H

#include "../Events/Event.h"
#include <functional>

class IEventCallback {
private:
    virtual void call(Event& event) = 0;
public:
    virtual ~IEventCallback() = default;
    void execute(Event& event);
};

template <typename TEvent, typename TOwner>
class EventCallback: public IEventCallback {
private:
    typedef void (TOwner::*FunctionToBeCalled)(TEvent&);

    TOwner* ownerOfFunction;
    FunctionToBeCalled functionToBeCalled;

    void call(Event& event) override;

public:
    EventCallback(TOwner* ownerOfFunction, FunctionToBeCalled functionToBeCalled){
        this->ownerOfFunction = ownerOfFunction;
        this->functionToBeCalled = functionToBeCalled;
    }
    ~EventCallback() override = default;
};

template<typename TEvent, typename TOwner>
void EventCallback<TEvent, TOwner>::call(Event &event) {
    std::invoke(functionToBeCalled, ownerOfFunction, static_cast<TEvent*>(event));
}


#endif //TEXTBASED_EVENTCALLBACK_H
