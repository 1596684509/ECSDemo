#include "World.h"


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


void World::registerDrawSystem(DrawSystem *system) {
	drawSystems.push_back(system);
}

void World::onUpdate(int delta) {

	for (auto& system : updateSystems) {

		system->onUpdate(this, delta);

	}

}

void World::onInput(GLFWwindow *window, int key, int scancode, int action, int mods) {

	InputEvent* input = getEventBus()->createEvent<InputEvent>();
	input->action = action;
	input->key = key;
	input->mods = mods;

	getEventBus()->emit<InputEvent>(input);

}

void World::onDraw() {

	for (auto& system : drawSystems) {
		system->onDraw(this);
	}

}

EventBus* World::getEventBus() {

	if (!eventBus) {
	
		eventBus = new EventBus();

	}

	return eventBus;

}
