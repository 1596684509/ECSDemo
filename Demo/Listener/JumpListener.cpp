#include "JumpListener.h"

JumpListener::JumpListener(World* world) : EventListener(world) {}

void JumpListener::onEvent(const JumpEvent* event) {

	ArcheType* archeType = event->archeType;
	int index = event->index;

	MoveState* moveState = archeType->getComponentForIndex<MoveState>(index);
	Velocity* velocity = archeType->getComponentForIndex<Velocity>(index);

	if (moveState && velocity) {
	
		moveState->canJump = false;
		moveState->isJump = true;
		velocity->y += -5;

	}

}