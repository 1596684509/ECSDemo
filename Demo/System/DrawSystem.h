#pragma once

#include "System.h"
#include "../Component/Camera.h"

class World;

class DrawSystem: public System {
public:
    virtual void onDraw(World* world, Camera* camera) = 0;

};
