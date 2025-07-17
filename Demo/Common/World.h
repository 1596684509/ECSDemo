#pragma once

#include <unordered_map>
#include <typeindex>
#include <string>
#include <vector>

#include <GLFW/glfw3.h>

#include "Entity.h"
#include "../Utils/BitMask.h"
#include "../Common/ArcheType.h"
#include "../Component/ComponentBitMaskDigits.h"
#include "../System/UpdateSystem.h"
#include "../System/DrawSystem.h"
#include "../System/InputSystem.h"

class World {

public:
	template <typename T>
	void addComponent(Entity* entity, T* component);
	template <typename... T>
	std::vector<ArcheType*> getArcheType();
	void commitComponent();

	void registerUpdateSystem(UpdateSystem* system);
	void registerInputSystem(InputSystem* system);
	void registerDrawSystem(DrawSystem* system);

	void onUpdate(int delta);
	void onInput(GLFWwindow* window, int key, int scancode, int action, int mods);
	void onDraw();

private:
	std::unordered_map<int, Entity*> entitys;
	std::unordered_map<std::string, ArcheType*> archeTypes;
	std::unordered_map<Entity*, std::unordered_map<std::type_index, Component*>> componentCash;
	std::vector<UpdateSystem*> updateSystems;
	std::vector<InputSystem*> inputSystems;
	std::vector<DrawSystem*> drawSystems;

};

template <typename T>
void World::addComponent(Entity* entity, T* component) {

	component->setBitMaskDigits(ComponentBitMaskDigits<T>::bitMaskDigits);
	componentCash[entity][typeid(T)] = component;

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

