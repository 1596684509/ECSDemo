#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "EventListener.h"
#include "../Event/InputEvent.h"
#include "../Common/World.h"
#include "../Event/JumpEvent.h"

#include "../Component/MoveState.h"
#include "../Component/InputKey.h"
#include "../Component/Jump.h"

class MoveInputListener: public EventListener<InputEvent>{

public:
	MoveInputListener(World* world);
	void onEvent(const InputEvent* event) override;

private:
	void onPress(int key, int mods);
	void onRelease(int key, int mods);
};