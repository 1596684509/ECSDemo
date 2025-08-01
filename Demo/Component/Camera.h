#pragma once

#include "Component.h"

class Camera : public Component {

public:
	float x;
	float y;
	int width;
	int height;
	void reset() override;
};