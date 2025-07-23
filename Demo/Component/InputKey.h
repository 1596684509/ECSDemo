#pragma once

#include "Component.h"

class InputKey: public Component{

public:
    int moveDown;
    int moveLeft;
    int moveRight;
    int jump;
    int run;

    void setMoveKey(int moveDown, int moveLeft, int moveRight);
    void setJumpKey(int jump);
    void setRun(int run);

};
