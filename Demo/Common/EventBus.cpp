#include "EventBus.h"

std::unordered_map<std::type_index, std::vector<Event*>> EventBus::eventPool;

void EventBus::releaseEvent(Event* event) {

	event->reset();
	eventPool[typeid(event)].emplace_back(event);

}

void EventBus::commit() {

    for (Event* event : eventList) {
        auto it = listeners.find(typeid(*event));
        if (it != listeners.end()) {
            for (auto& listener : it->second) {
                listener->handler(event);
                event->runEnd = true;
            }
        }
    }

    clearEventList();

}

void EventBus::clearEventList() {

    for (Event* e : eventList) {

        if (e->runEnd) {
            e->reset();
            eventPool[typeid(e)].emplace_back(e);
        }

    }

    eventList.erase(std::remove_if(eventList.begin(), eventList.end(), [](Event* e) { return e->runEnd; }), eventList.end());

}

void EventBus::emit(Event* event) {

    eventList.emplace_back(event);

}