#pragma once

#include <GLFW/glfw3.h>

#include "System.h"

class World;


class InputSystem: public System {

public:
    virtual void onPress(World* world, GLFWwindow* window, int key, int scancode, int mods) = 0;
    virtual void onRelease(World* world, GLFWwindow* window, int key, int scancode, int mods) = 0;
    virtual void onRepeat(World* world, GLFWwindow* window, int key, int scancode, int mods) = 0;

};
