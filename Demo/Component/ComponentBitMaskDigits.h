#pragma once

#include "InputKey.h"
#include "MoveState.h"
#include "Position.h"
#include "Velocity.h"
#include "Gravity.h"
#include "Jump.h"
#include "Camera.h"

template<typename T>
struct ComponentBitMaskDigits;

template<>
struct ComponentBitMaskDigits<Position> {
public:
	static constexpr int bitMaskDigits = (int)ComponentType::Position;
};

template<>
struct ComponentBitMaskDigits<Velocity> {
public:
	static constexpr int bitMaskDigits = (int)ComponentType::Velocity;
};

template<>
struct ComponentBitMaskDigits<InputKey> {
public:
	static constexpr int bitMaskDigits = (int)ComponentType::InputKey;
};

template<>
struct ComponentBitMaskDigits<MoveState> {
public:
	static constexpr int bitMaskDigits = (int)ComponentType::MoveState;
};

template<>
struct ComponentBitMaskDigits<Gravity> {
public:
	static constexpr int bitMaskDigits = (int)ComponentType::Gravity;
};

template<>
struct ComponentBitMaskDigits<Jump> {
public:
	static constexpr int bitMaskDigits = (int)ComponentType::Jump;
};

template<>
struct ComponentBitMaskDigits<Camera> {
public:
	static constexpr int bitMaskDigits = (int)ComponentType::Camera;
};
