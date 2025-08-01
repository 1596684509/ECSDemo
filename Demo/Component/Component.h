#pragma once

#include "../Interface/PoolObject.h"

class Component: public PoolObject {

public:
	Component() = default;
	virtual ~Component() = default;
	void setBitMaskDigits(int bitMaskDigits);
	int getBitMaskDigits();
	void reset() override;

private:
	int bitMaskDigits;

};