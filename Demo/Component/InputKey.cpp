#include "InputKey.h"

InputKey::InputKey(InputKeyBuilder& builder) {

    moveDown = builder.moveDown;
    moveLeft = builder.moveLeft;
    moveRight = builder.moveRight;
    jump = builder.jump;
    run = builder.run;

}

void InputKey::setMoveKey(int moveDown, int moveLeft, int moveRight) {

    this->moveDown = moveDown;
    this->moveLeft = moveLeft;
    this->moveRight = moveRight;

}

void InputKey::setJumpKey(int jump) {
    this->jump = jump;
}

void InputKey::setRun(int run) {
    this->run = run;
}

InputKey* InputKey::InputKeyBuilder::build() {

    return new InputKey(*this);

}

InputKey::InputKeyBuilder& InputKey::InputKeyBuilder::setMoveDown(int key) {

    moveDown = key;
    return *this;
}

InputKey::InputKeyBuilder& InputKey::InputKeyBuilder::setMoveLeft(int key) {

    moveLeft = key;
    return *this;

}

InputKey::InputKeyBuilder& InputKey::InputKeyBuilder::setMoveRight(int key) {

    moveRight = key;
    return *this;

}

InputKey::InputKeyBuilder& InputKey::InputKeyBuilder::setJump(int key) {

    jump = key;
    return *this;

}

InputKey::InputKeyBuilder& InputKey::InputKeyBuilder::setRun(int key) {

    run = key;
    return *this;

}
