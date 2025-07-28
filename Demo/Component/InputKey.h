#pragma once

#include "Component.h"

class InputKey: public Component{

public:
    class InputKeyBuilder {
    public:
        InputKeyBuilder& setMoveDown(int key);
        InputKeyBuilder& setMoveLeft(int key);
        InputKeyBuilder& setMoveRight(int key);
        InputKeyBuilder& setJump(int key);
        InputKeyBuilder& setRun(int key);
        InputKey* build();

    private:
        int moveDown;
        int moveLeft;
        int moveRight;
        int jump;
        int run;

        friend class InputKey;
    };

public:
    int moveDown;
    int moveLeft;
    int moveRight;
    int jump;
    int run;

    void setMoveKey(int moveDown, int moveLeft, int moveRight);
    void setJumpKey(int jump);
    void setRun(int run);

private:
    InputKey(InputKeyBuilder& builder);

};
