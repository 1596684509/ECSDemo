#include "MoveInputSystem.h"

void MoveInputSystem::onPress(World *world, GLFWwindow *window, int key, int scancode, int mods) {

    std::vector<ArcheType*> archeTypes = world->getArcheType<MoveState, InputKey>();
    for (ArcheType* archeType : archeTypes) {

        std::vector<MoveState*> moves = archeType->getComponts<MoveState>();
        std::vector<InputKey*> inputKeys = archeType->getComponts<InputKey>();

        for (int i = 0; i < archeType->getEntityCount(); ++i) {

            MoveState* moveState = moves[i];
            InputKey* inputKey = inputKeys[i];

            if (key == inputKey->moveLeft) moveState->isLeft = true;
            if (key == inputKey->moveRight) moveState->isRight = true;

        }

    }

}

void MoveInputSystem::onRelease(World *world, GLFWwindow *window, int key, int scancode, int mods) {

    std::vector<ArcheType*> archeTypes = world->getArcheType<MoveState, InputKey>();
    for (ArcheType* archeType : archeTypes) {

        std::vector<MoveState*> moves = archeType->getComponts<MoveState>();
        std::vector<InputKey*> inputKeys = archeType->getComponts<InputKey>();

        for (int i = 0; i < archeType->getEntityCount(); ++i) {

            MoveState* moveState = moves[i];
            InputKey* inputKey = inputKeys[i];

            if (key == inputKey->moveLeft) moveState->isLeft = false;
            if (key == inputKey->moveRight) moveState->isRight = false;

        }

    }

}

void MoveInputSystem::onRepeat(World *world, GLFWwindow *window, int key, int scancode, int mods) {
}
