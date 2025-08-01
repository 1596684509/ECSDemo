#pragma once

#include <windows.h>
#include <vector>
#include <cmath>
#include <iostream>

#include "DrawSystem.h"
#include "../Common/World.h"
#include "../Common/Const.h"


class CharacterDrawSystem: public DrawSystem {
    void onDraw(World *world, Camera* camera) override;
};
