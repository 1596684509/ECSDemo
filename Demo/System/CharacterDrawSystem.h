#pragma once

#include <windows.h>
#include <vector>
#include <cmath>
#include <GL/gl.h>

#include "DrawSystem.h"
#include "../Common/World.h"


class CharacterDrawSystem: public DrawSystem {
    void onDraw(World *world) override;
};
