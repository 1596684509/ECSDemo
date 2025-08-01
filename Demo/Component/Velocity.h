#pragma once

#include "Component.h"
#include "ComponentType.h"

class Velocity : public Component {

public:
	float x;
	float y;
	Velocity() = default;
	Velocity(float x, float y);

};