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