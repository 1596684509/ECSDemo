#pragma once

#include "Component.h"

class Gravity: public Component {

public:
	Gravity() = default;
	Gravity(float gravity);
	bool canGravity = true;
	float gravity;
	void reset() override;

};