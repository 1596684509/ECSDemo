#pragma once

#include "System.h"

class World;

class UpdateSystem: public System {
public:
    virtual void onUpdate(World* world, int delta) = 0;

};
