#pragma once

#include <vector>
#include <unordered_map>
#include <typeindex>
#include <functional>

#include "../Event/Event.h"
#include "../Listener/AbstractEventListener.h"
#include "../Listener/EventListener.h"

#include "../Utils/PoolHandler.h"

class EventBus {

public:

	//注册事件
	template<typename T>
	void registerEventListener(EventListener<T>* listener);
	//发布事件
	void emit(Event* event);
	//提交并执行
	void commit();
	void clearEventList();

private:
	//待处理事件队列
	std::vector<Event*> eventList;
	//监听器
	std::unordered_map<std::type_index, std::vector<AbstractEventListener*>> listeners;

};

template<typename T>
void EventBus::registerEventListener(EventListener<T>* listener) {

	auto& vec = listeners[typeid(T)];
	vec.push_back(listener);

}

