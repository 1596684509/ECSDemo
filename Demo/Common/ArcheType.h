#pragma once

#include <vector>
#include <unordered_map>
#include <typeindex>

#include "../Common/Entity.h"
#include "../Component/Component.h"
#include "../Utils/BitMask.h"
#include "../Component/ComponentBitMaskDigits.h"

class ArcheType {

public:
	//计算集合值
	bool build();
	BitMask* getBitMask();
	void addEntity(Entity* entity, Component* com);
	void addEntity(ArcheType& archeType);
	Entity* getEntity(size_t index);
	int hasEntity(Entity* entity);
	template<typename... T>
	bool hasComponent();
	template<typename T>
	std::vector<T*> getComponents();
	template<typename T>
	T* getComponentForIndex(size_t index);
	std::unordered_map<std::type_index, Component*> getAllComponentForIndex(size_t index);
	//获取组件种类个数
	int getComponentCount();
	//获取实体个数
	int getEntityCount();

private:
	BitMask* bitMask = nullptr;
	std::vector<Entity*> entitys;
	std::unordered_map<std::type_index, std::vector<Component*>> components;

};

template<typename... T>
bool ArcheType::hasComponent() {

	return (... && (bitMask->get(ComponentBitMaskDigits<T>::bitMaskDigits)));

}

template<typename T>
std::vector<T*> ArcheType::getComponents() {
	std::vector<T*> result;

	auto it = components.find(typeid(T));
	if (it != components.end()) {
		for (Component* c : it->second) {
			if (T* real = dynamic_cast<T*>(c)) {
				result.push_back(real);
			}
		}
	}

	return result;
}

template<typename T>
T* ArcheType::getComponentForIndex(size_t index) {
	if (hasComponent<T>()) {
		auto& vec = components[typeid(T)];
		return static_cast<T*>(vec.at(index));
	}
	return nullptr;
}