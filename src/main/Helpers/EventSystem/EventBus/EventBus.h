#ifndef TEXTBASED_EVENTBUS_H
#define TEXTBASED_EVENTBUS_H
#include <map>
#include <typeindex>
#include <list>
#include <memory>
#include "../EventCallback/EventCallback.h"


typedef std::list<std::unique_ptr<IEventCallback>>EventHandlerList;

class EventBus {
private:
    std::map<std::type_index, std::unique_ptr<EventHandlerList>> listeners;


public:
    virtual ~EventBus();

    EventBus();

    template <typename TEvent, typename TOwner>
    void listenToEvent(TOwner* ownerOfFunction, void (TOwner::*functionToBeCalled)(TEvent&));

    template <typename TEvent, typename ...TArgs>
    void emitEvent(TArgs&& ...args);

};

template<typename TEvent, typename TOwner>
void EventBus::listenToEvent(TOwner *ownerOfFunction, void (TOwner::*functionToBeCalled)(TEvent &)) {
    if (listeners[typeid(TEvent)] == nullptr){
        listeners[typeid(TEvent)] = std::make_unique<EventHandlerList>();
    }

    auto listener = std::make_unique<EventCallback<TOwner, TEvent>>(ownerOfFunction, functionToBeCalled);
    listeners[typeid(TEvent)]->push_back(std::move(listener));
}

template<typename TEvent, typename ...TArgs>
void EventBus::emitEvent(TArgs&& ...args) {
    auto handlers = listeners[typeid(TEvent)].get();

    if (handlers == nullptr) return;

    for (auto & iterator : *handlers){
        auto handler = iterator.get();
        TEvent event(std::forward<TArgs>(args)...);
        handler->execute(event);
    }
}



#endif //TEXTBASED_EVENTBUS_H
