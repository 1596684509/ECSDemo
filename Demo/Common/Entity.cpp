#include "Entity.h"

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

Entity* Entity::createGloBalEntity() {

	return new Entity(0);

}