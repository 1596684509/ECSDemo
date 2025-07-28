#pragma once

#include <functional>

#include "Component.h"
#include "ComponentType.h"

class Position: public Component {

public:
	float x;
	float y;

	Position(float x, float y);
	bool operator==(const Position& other) const;

};



