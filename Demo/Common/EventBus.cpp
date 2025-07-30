#include "EventBus.h"

void EventBus::commit() {

    for (Event* event : eventList) {

        auto&& it = listeners.find(typeid(*event));
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
    PoolHandler* poolHandler = PoolHandler::getInstance();

    // 暂存需要释放的对象
    std::vector<Event*> toRelease;

    // 保留未处理完的事件
    eventList.erase(std::remove_if(eventList.begin(), eventList.end(), [&](Event* e) {
        if (e->runEnd) {
            toRelease.push_back(e);  // 还没 reset，状态是完整的
            return true;             // 从 eventList 中删除
        }
        return false;
        }), eventList.end());

    // 全部释放
    for (Event* e : toRelease) {
        e->runEnd = false;
        poolHandler->release(e); // 现在可以 reset 了
    }
}

void EventBus::emit(Event* event) {

    eventList.emplace_back(event);

}