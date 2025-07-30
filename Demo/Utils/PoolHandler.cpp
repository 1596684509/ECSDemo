#include "PoolHandler.h"

PoolHandler::PoolHandler() {};

PoolHandler* PoolHandler::getInstance() {

	static PoolHandler handler;
	return &handler;

}

void PoolHandler::release(PoolObject* obj) {
	obj->reset();
	pool[typeid(*obj)].push(obj); 
}

