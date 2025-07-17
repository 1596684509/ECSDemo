#pragma once

#include "Position.h"
#include "Velocity.h"

template<typename T>
struct ComponentBitMaskDigits;

template<>
struct ComponentBitMaskDigits<Position> {
public:
	static constexpr int bitMaskDigits = 0;
};

template<>
struct ComponentBitMaskDigits<Velocity> {
public:
	static constexpr int bitMaskDigits = 1;
};