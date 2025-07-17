#pragma once

#include <unordered_map>
#include <typeindex>
#include <string>
#include <vector>

#include "Entity.h"

#include "../Utils/BitMask.h"
#include "../Common/ArcheType.h"
#include "../Component/ComponentBitMaskDigits.h"


class World {

public:
	template <typename T>
	void addComponent(Entity* entity, T* component);
	template <typename... T>
	std::vector<ArcheType*> getArcheType();
	void commitComponent();

private:
	std::unordered_map<int, Entity*> entitys;
	std::unordered_map<std::string, ArcheType*> archeTypes;
	std::unordered_map<Entity*, std::unordered_map<std::type_index, Component*>> componentCash;
	
};

template <typename T>
void World::addComponent(Entity* entity, T* component) {

	component->setBitMaskDigits(ComponentBitMaskDigits<T>::bitMaskDigits);
	componentCash[entity][typeid(T)] = component;

}

template <typename... T>
std::vector<ArcheType*> World::getArcheType() {
	std::vector<ArcheType*> result;
	for (auto* archetype : archeTypes) {
		if (archetype->hasComponent<T...>()) {
			result.push_back(archetype);
		}
	}
	return result;
}

