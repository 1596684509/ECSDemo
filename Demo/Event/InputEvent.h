#pragma once

#include "Event.h"

class InputEvent : public Event {

public:
	int key;
	int action;
	int mods;
	void reset() override;

};