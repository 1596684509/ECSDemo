#pragma once

#include "Event.h"
#include "../Common/Entity.h"
#include "../Common/ArcheType.h"

class JumpEvent : public Event {

public:
	ArcheType* archeType;
	int index; //组件在集合中的下标
	void reset() override;

};