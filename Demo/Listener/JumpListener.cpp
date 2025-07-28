#include "JumpListener.h"

JumpListener::JumpListener(World* world) : EventListener(world) {}

void JumpListener::onEvent(const JumpEvent* event) {

	ArcheType* archeType = event->archeType;
	int index = event->index;

	MoveState* moveState = archeType->getComponentForIndex<MoveState>(index);
	Velocity* velocity = archeType->getComponentForIndex<Velocity>(index);
	Jump* jump = archeType->getComponentForIndex<Jump>(index);

	if (moveState && velocity && jump) {
	
		jump->nowJumpCount++;

		if (jump->maxJumpCount != -1 && jump->nowJumpCount >= jump->maxJumpCount) {
			moveState->canJump = false;
		}

		moveState->isJump = true;
		velocity->y = jump->jumpPower;

	}

}