#pragma once

#include "../Utils/UUIDHandler.h"
#include "../Interface/PoolObject.h"

class Entity: public PoolObject {

public:
	Entity();
	int getUUID();
	bool operator==(const Entity& entity);
	bool operator!=(const Entity& entity);
	static Entity* getGloBalEntity();
	static Entity* getPlayer();
	void reset();

private:
	//0是全局实体
	Entity(int uuid);
	int uuid;
	static Entity* gloBalEntity;
	static Entity* player;
};
