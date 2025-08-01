#include "Gravity.h"

Gravity::Gravity(float gravity) : gravity(gravity) {

}

void Gravity::reset() {

	canGravity = true;
	gravity = 0;

}