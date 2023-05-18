#include "EventCallback.h"

void IEventCallback::execute(Event &event) {
    call(event);
}
