#pragma once

#include "Component.h"

class MoveState: public Component {

public:
    bool canMove = true;
    bool isMoving = false;
    bool isLeft = false;
    bool isRight = false;
    bool isDown = false;
    bool isJump = false;

};
