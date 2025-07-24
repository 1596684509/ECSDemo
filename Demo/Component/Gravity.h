#pragma once

#include "Component.h"

class Gravity: public Component {

public:
	Gravity(float gravity);
	bool canGravity = true;
	float gravity;

};