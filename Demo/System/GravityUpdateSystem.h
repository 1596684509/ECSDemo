#pragma once

#include "UpdateSystem.h"
#include "../Common/World.h"
#include "../Common/Const.h"
#include "../Component/Velocity.h"
#include "../Component/Position.h"

class GravityUpdateSystem : public UpdateSystem {
public:
	void onUpdate(World* world, int delta);

};