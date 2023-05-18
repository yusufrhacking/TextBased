#include "EventFunctionWrapper.h"

void IEventFunctionWrapper::execute(Event &event) {
    call(event);
}
