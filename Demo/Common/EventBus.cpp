#include "EventBus.h"

void EventBus::releaseEvent(Event* event) {

	event->reset();
	eventPool[typeid(event)].emplace_back(event);

}

void EventBus::commit() {

    for (auto& event : eventList) {
        auto it = listeners.find(typeid(*event));
        if (it != listeners.end()) {
            for (auto& handler : it->second) {
                handler(*event);
            }
        }
    }

    clearEventList();

}

void EventBus::clearEventList() {

    for (Event* e : eventList) {
    
        e->reset();
        eventPool[typeid(e)].emplace_back(e);

    }

    eventList.clear();

}