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
	bool build();
	BitMask* getBitMask();
	void addEntity(Entity* entity, Component* com);
	void addEntity(ArcheType* archeType);
	Entity* getEntity(size_t index);
	int hasEntity(Entity* entity);
	template<typename... T>
	bool hasComponent();
	template<typename T>
	std::vector<T*> getComponts();
	int getComponentCount();
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
std::vector<T*> ArcheType::getComponts() {
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