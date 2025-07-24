#pragma once

class Event {

public:
	bool runEnd = false;
	virtual void reset() = 0;

};