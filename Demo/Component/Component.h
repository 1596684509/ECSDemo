#pragma once

class Component {

public:
	Component() = default;
	virtual ~Component() = default;
	void setBitMaskDigits(int bitMaskDigits);
	int getBitMaskDigits();

private:
	int bitMaskDigits;

};