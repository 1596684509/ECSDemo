#pragma once

#include <vector>

#include "UpdateSystem.h"
#include "../Component/InputKey.h"
#include "../Component/MoveState.h"
#include "../Component/Jump.h"
#include "../Common/ArcheType.h"
#include "../Common/World.h"
#include "../Common/Const.h"



class MoveUpdateSystem : public UpdateSystem {
public:
    void onUpdate(World* world, int delta) override;

private:
    void setCameraPosition(World* world, const Position* position);
};
