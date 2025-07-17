#pragma once

#include "Component.h"

class InputKey: public Component{

public:
    int moveDown;
    int moveLeft;
    int moveRight;
    int jump;

    void setMoveKey(int moveDown, int moveLeft, int moveRight);
    void setJumpKey(int jump);

};
