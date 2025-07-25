#pragma once
#include "Component.h"

class Jump : public Component {
public:

	Jump(int maxJumpCount, float jumpPower);

	int maxJumpCount;
	float jumpPower;
	int nowJumpCount;
};