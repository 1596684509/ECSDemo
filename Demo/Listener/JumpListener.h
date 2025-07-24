#pragma once

#include "EventListener.h"
#include "../Event/JumpEvent.h"
#include "../Common/ArcheType.h"
#include "../Component/Velocity.h"
#include "../Component/MoveState.h"

class JumpListener: public EventListener<JumpEvent> {
public:
	JumpListener(World* world);
	void onEvent(const JumpEvent* event) override;
};