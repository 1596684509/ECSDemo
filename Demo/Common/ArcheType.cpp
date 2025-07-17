#include "ArcheType.h"

BitMask* ArcheType::getBitMask() {

	return bitMask;

}

bool ArcheType::build() {

	if (entitys.size() == 0) {
	
		return false;

	}

	BitMask* bit = new BitMask();

	for (auto& com : components) {
	
		size_t bitMaskDigits = com.second[0]->getBitMaskDigits();
		bit->set(bitMaskDigits);

	}

	bitMask = bit;

	return true;

}

void ArcheType::addEntity(Entity* entity, Component* com) {

	int index = hasEntity(entity);

	if (index == -1) {

		entitys.push_back(entity);

	}
	components[typeid(*com)].push_back(com);

}

int ArcheType::hasEntity(Entity* entity) {

	for (int i = 0; i < entitys.size(); i++) {
	
		if (entitys[i] == entity) {
		
			return i;

		}

	}

	return -1;

}

void ArcheType::addEntity(ArcheType* archeType) {

	for (int i = 0; i < archeType->entitys.size(); i++) {

		for (auto& com : archeType->components) {
		
			addEntity(archeType->getEntity(i), com.second[i]);

		}

	}

}

Entity* ArcheType::getEntity(size_t index) {

	if (index < entitys.size()) {
	
		return entitys[index];

	}

	return nullptr;

}

int ArcheType::getComponentCount() {
	return components.size();
}

int ArcheType::getEntityCount() {
	return entitys.size();
}
