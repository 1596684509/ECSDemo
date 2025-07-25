#pragma once

#include "Component.h"

class MoveState: public Component {

public:
    bool canMove = true;
    bool canJump = true;
    bool isMoving = false;
    bool isLeft = false;
    bool isRight = false;
    bool isDown = false;
    bool isJump = false;
    bool isRun = false;

    bool inGround = false;

};
