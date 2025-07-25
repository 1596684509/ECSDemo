#pragma once

#include "../Event/Event.h"

class World;

class AbstractEventListener {

public:
	explicit AbstractEventListener(World* world);
	virtual ~AbstractEventListener() = default;
	virtual void handler(const Event* event) = 0;

protected:
	World* world;

};
