#pragma once

#include <unordered_map>
#include <stack>
#include <typeindex>
#include <type_traits>

#include "../Interface/PoolObject.h"

class PoolHandler {

public:
	PoolHandler(const PoolHandler&) = delete;
	PoolHandler& operator=(const PoolHandler&) = delete;
	static PoolHandler* getInstance();

	void release(PoolObject* obj);

	template<typename T>
	T* getObject() {
	
		static_assert(std::is_base_of<PoolObject, T>::value, "T 未继承 PoolObject");
		auto& stk = pool[std::type_index(typeid(T))];
		T* obj;
		if (stk.empty()) {
		
			obj = new T();

		}
		else {
		
			obj = static_cast<T*>(stk.top());
			stk.pop();

		}

		return obj;

	}

private:
	PoolHandler();
	std::unordered_map<std::type_index, std::stack<PoolObject*>> pool;

};