#include "Entity.h"

Entity* Entity::gloBalEntity = nullptr;
Entity* Entity::player = nullptr;

Entity::Entity() {

	uuid = UUIDHandler::createUUID();

};

Entity::Entity(int uuid): uuid(uuid) {

};
int Entity::getUUID() {

	return uuid;

};

bool Entity::operator==(const Entity& entity){
	return entity.uuid == this->uuid;
}
bool Entity::operator!=(const Entity& entity){
	return !(*this == entity);
}

Entity* Entity::getGloBalEntity() {

	if (!gloBalEntity) {
	
		gloBalEntity = new Entity(0);

	}

	return gloBalEntity;

}

Entity* Entity::getPlayer() {

	if (!player) {

		player = new Entity(1);

	}

	return player;

}

void Entity::reset() {
	uuid = UUIDHandler::createUUID();
}