#pragma once

#include <vector>

#include "UpdateSystem.h"
#include "../Component/InputKey.h"
#include "../Component/MoveState.h"
#include "../Common/ArcheType.h"
#include "../Common/World.h"



class MoveUpdateSystem: public UpdateSystem{
public:
    void onUpdate(World* world, int delta) override;
};
