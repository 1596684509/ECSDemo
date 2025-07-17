#pragma once

#include "../Utils/UUIDHandler.h"

class Entity {

public:
	Entity();
	int getUUID();
	bool operator==(const Entity& entity);
	bool operator!=(const Entity& entity);

private:
	//0是全局实体
	int uuid;

};
