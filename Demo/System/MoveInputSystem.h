#pragma once

#include <vector>

#include "InputSystem.h"
#include "../Common/World.h"
#include "../Common/ArcheType.h"

class MoveInputSystem: public InputSystem {
public:
    void onPress(World *world, GLFWwindow *window, int key, int scancode, int mods) override;

    void onRelease(World *world, GLFWwindow *window, int key, int scancode, int mods) override;

    void onRepeat(World *world, GLFWwindow *window, int key, int scancode, int mods) override;
};
