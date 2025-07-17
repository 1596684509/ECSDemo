#include "InputKey.h"

void InputKey::setMoveKey(int moveDown, int moveLeft, int moveRight) {

    this->moveDown = moveDown;
    this->moveLeft = moveLeft;
    this->moveRight = moveRight;

}

void InputKey::setJumpKey(int jump) {
    this->jump = jump;
}
