#pragma once

#include <vector>
#include <unordered_map>
#include <typeindex>
#include <functional>

#include "../Event/Event.h"

class EventBus {

public:
	template<typename T>
	using Handler = std::function<void(const T*)>;
	//创建事件
	template<typename T>
	T* createEvent();
	//归还事件
	void releaseEvent(Event* event);
	//注册事件
	template<typename T>
	void registerEvent(Handler<T> handler);
	//发布事件
	template<typename T>
	void emit(const T* event);
	//提交并执行
	void commit();
	void clearEventList();

private:
	//事件池
	static std::unordered_map<std::type_index, std::vector<Event*>> eventPool;
	//待处理事件队列
	std::vector<Event*> eventList;
	//监听器
	std::unordered_map<std::type_index, std::vector<std::function<void(const Event&)>>> listeners;

};

template<typename T>
T* EventBus::createEvent() {

	auto& events = eventPool[typeid(T)];

	if (events.empty()) {
	
		return new T();

	}else {

		T* e = events.back();
		events.pop_back();
		return e;

	}

}

template<typename T>
void EventBus::registerEvent(Handler<T> handler) {

	auto& vec = listeners[typeid(T)];
	vec.push_back([handler](const Event& e) {
		handler(static_cast<const T&>(e));
		});

}

template<typename T>
void EventBus::emit(const T* event) {

	eventList.emplace_back(event);

}