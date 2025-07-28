#pragma once

#include <memory>


#include "AbstractEventListener.h"
#include "../Event/Event.h"

/*
* 所有事件监听器的父类
*/
template<typename EventType>
class EventListener : public AbstractEventListener {

public:
	explicit EventListener(World* world);
	void handler(const Event* event) override;
	virtual void onEvent(const EventType* event) = 0;

};

template<typename EventType>
EventListener<EventType>::EventListener(World* world) : AbstractEventListener(world) {

}

template<typename EventType>
void EventListener<EventType>::handler(const Event* event) {

	onEvent(static_cast<const EventType*>(event));

}