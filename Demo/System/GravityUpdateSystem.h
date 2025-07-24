#pragma once

#include "UpdateSystem.h"
#include "../Common/World.h"
#include "../Common/Const.h"

class GravityUpdateSystem : public UpdateSystem {
public:
	void onUpdate(World* world, int delta);

};