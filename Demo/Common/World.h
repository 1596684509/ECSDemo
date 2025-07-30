#pragma once

#include <unordered_map>
#include <typeindex>
#include <string>
#include <vector>

#include <GLFW/glfw3.h>

#include "Entity.h"
#include "../Utils/BitMask.h"
#include "../Utils/PoolHandler.h"
#include "../Common/ArcheType.h"
#include "../Component/ComponentBitMaskDigits.h"
#include "../System/UpdateSystem.h"
#include "../System/DrawSystem.h"
#include "../Event/InputEvent.h"
#include "EventBus.h"

class World {

public:

	template <typename T>
	void addComponent(Entity* entity, T* component);
	template <typename... T>
	std::vector<ArcheType*> getArcheType();
	//将组件缓存提交至主系统
	void commitComponent();

	void registerUpdateSystem(UpdateSystem* system);
	void registerDrawSystem(DrawSystem* system);

	void onUpdate(int delta);
	void onInput(GLFWwindow* window, int key, int scancode, int action, int mods);
	void onDraw();

	EventBus* getEventBus();

private:
	//记录实体和其组件集位掩码
	std::unordered_map<Entity*, std::string> entitys;
	std::unordered_map<std::string, ArcheType*> archeTypes;
	std::unordered_map<Entity*, std::unordered_map<std::type_index, Component*>> componentCache;
	std::vector<UpdateSystem*> updateSystems;
	std::vector<DrawSystem*> drawSystems;
	EventBus* eventBus = nullptr;

};

template <typename T>
void World::addComponent(Entity* entity, T* component) {

	component->setBitMaskDigits(ComponentBitMaskDigits<T>::bitMaskDigits);
	componentCache[entity][typeid(T)] = component;

}

template <typename... T>
std::vector<ArcheType*> World::getArcheType() {
	std::vector<ArcheType*> result;
	for (auto& archetype : archeTypes) {
		if (archetype.second->hasComponent<T...>()) {
			result.push_back(archetype.second);
		}
	}
	return result;
}

