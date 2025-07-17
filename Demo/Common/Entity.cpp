#include "Entity.h"

Entity::Entity() {

	uuid = UUIDHandler::createUUID();

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
