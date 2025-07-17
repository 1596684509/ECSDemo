#pragma once

class Component {

public:
	Component() = default;
	void setBitMaskDigits(int bitMaskDigits);
	int getBitMaskDigits();

private:
	int bitMaskDigits;

};