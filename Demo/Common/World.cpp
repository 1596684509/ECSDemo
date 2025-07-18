#include "World.h"

#include "../System/InputSystem.h"

void World::commitComponent() {

	for (auto& entity : componentCash) {

		Entity* ent = entity.first;
		ArcheType archeType;
	
		for (auto& com : entity.second) {
		
			archeType.addEntity(ent, com.second);

		}

		if (archeType.build()) {

			std::string bitmask = archeType.getBitMask()->toString();

			if (archeTypes.find(bitmask) != archeTypes.end()) {
			
				archeTypes[bitmask]->addEntity(&archeType);

			}else {
			
				ArcheType* addObj = new ArcheType();
				addObj->addEntity(&archeType);
				addObj->build();
				archeTypes[addObj->getBitMask()->toString()] = addObj;

			}

		}

		entitys[ent->getUUID()] = ent;

	}

	componentCash.clear();

}

void World::registerUpdateSystem(UpdateSystem* system) {

	updateSystems.push_back(system);

}

void World::registerInputSystem(InputSystem *system) {
	inputSystems.push_back(system);
}

void World::registerDrawSystem(DrawSystem *system) {
	drawSystems.push_back(system);
}

void World::onUpdate(int delta) {

	for (auto& system : updateSystems) {

		system->onUpdate(this, delta);

	}

}

void World::onInput(GLFWwindow *window, int key, int scancode, int action, int mods) {

	for (auto& system : inputSystems) {

		if (action == GLFW_PRESS) {
		
			system->onPress(this, window, key, scancode, mods);

		}else if (action == GLFW_RELEASE) {
		
			system->onRelease(this, window, key, scancode, mods);

		}else {
		
			system->onRepeat(this, window, key, scancode, mods);

		}

	}

}

void World::onDraw() {

	for (auto& system : drawSystems) {
		system->onDraw(this);
	}

}
