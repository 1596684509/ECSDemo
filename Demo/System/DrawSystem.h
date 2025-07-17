#pragma once

#include "System.h"

class World;

class DrawSystem: public System {
public:
    virtual void onDraw(World* world) = 0;

};
