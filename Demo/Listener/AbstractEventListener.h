#pragma once

#include "../Event/Event.h"

class World;

class AbstractEventListener {

public:
	AbstractEventListener(World* world);
	~AbstractEventListener() = default;
	virtual void handler(const Event* event) = 0;

protected:
	World* world;

};
